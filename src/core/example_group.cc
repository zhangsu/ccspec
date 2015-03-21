#include "ccspec/core/example_group.h"

#include "ccspec/core/unexpected_throw.h"
#include "ccspec/support/exception.h"

namespace ccspec {
namespace core {

using std::current_exception;
using std::exception_ptr;
using std::function;
using std::list;
using std::make_exception_ptr;
using std::stack;
using std::string;
using ccspec::core::UnexpectedThrow;

stack<ExampleGroup*> groups_being_defined;

// Public methods.

void ExampleGroup::catchException(
    function<void()> func,
    function<void(exception_ptr)> handleException) {
  try {
    func();
  } catch (const ccspec::support::Exception& e) {
    // The exception can only be a Mismatch as no other CCSpec
    // exceptions should be thrown inside the spec code.
    handleException(current_exception());
  } catch (const std::exception& e) {
    // Wrap other C++ exceptions in a CCSpec exception.
    handleException(make_exception_ptr(UnexpectedThrow(e)));
  }
}

ExampleGroup::~ExampleGroup() {
  for (auto child : children_)
    delete child;
}

void ExampleGroup::addExample(Example example) {
  examples_.push_back(example);
}

void ExampleGroup::addBeforeEachHook(BeforeHook hook) {
  before_each_hooks_.push_back(hook);
}

void ExampleGroup::addBeforeAllHook(BeforeHook hook) {
  before_all_hooks_.push_back(hook);
}

void ExampleGroup::addAfterEachHook(AfterHook hook) {
  after_each_hooks_.push_back(hook);
}

void ExampleGroup::addAfterAllHook(AfterHook hook) {
  after_all_hooks_.push_back(hook);
}

void ExampleGroup::addAroundHook(AroundHook hook) {
  around_hooks_.push_back(hook);
}

bool ExampleGroup::run(Reporter& reporter) const {
  list<BeforeHook> before_each_hooks;
  list<AfterHook> after_each_hooks;
  list<AroundHook> around_hooks;
  return run(reporter, before_each_hooks, after_each_hooks, around_hooks);
}

// Private methods.

ExampleGroup::ExampleGroup(string desc) : desc_(desc) {}

void ExampleGroup::addChild(const ExampleGroup* example_group) {
  children_.push_back(example_group);
}

bool ExampleGroup::run(Reporter& reporter,
                       list<BeforeHook>& before_each_hooks,
                       list<AfterHook>& after_each_hooks,
                       list<AroundHook>& around_hooks) const {
  auto first_new_before_each = before_each_hooks.insert(
      before_each_hooks.end(),
      before_each_hooks_.begin(),
      before_each_hooks_.end());
  auto first_new_after_each = after_each_hooks.insert(
      after_each_hooks.end(),
      after_each_hooks_.begin(),
      after_each_hooks_.end());
  auto first_new_around = around_hooks.insert(
      around_hooks.end(),
      around_hooks_.begin(),
      around_hooks_.end());
  bool succeeded = true;

  reporter.exampleGroupStarted(desc_);
  catchException([&] {
    for (auto hook : before_all_hooks_)
      hook();
    for (auto const& example : examples_) {
      // `succeeded` must be on the RHS of && to avoid short-circuit.
      succeeded = example.run(reporter,
          before_each_hooks,
          after_each_hooks,
          around_hooks) && succeeded;
    }
    for (auto child : children_) {
        // `succeeded` must be on the RHS of && to avoid short-circuit.
        succeeded = child->run(
            reporter,
            before_each_hooks,
            after_each_hooks,
            around_hooks) && succeeded;
    }
  }, [&](exception_ptr e) {
    // Exceptions are all handled when running an example, so exceptions
    // here can only be thrown from before all hooks, thus fail all
    // descendant examples.
    failWithException(reporter, e);
    succeeded = false;
  });
  // Continue running after all hooks regardless of execution result.
  catchException([this] {
    for (auto hook : after_all_hooks_)
        hook();
  }, [&](exception_ptr e) {
    reporter.afterAllHookFailed(e);
    succeeded = false;
  });
  reporter.exampleGroupFinished(desc_);
  around_hooks.erase(first_new_around, around_hooks.end());
  after_each_hooks.erase(first_new_after_each, after_each_hooks.end());
  before_each_hooks.erase(first_new_before_each, before_each_hooks.end());

  return succeeded;
}

void ExampleGroup::failWithException(Reporter& reporter,
                                     exception_ptr e) const {
  for (auto const& example : examples_)
    example.failWithException(reporter, e);
  for (auto child : children_)
    child->failWithException(reporter, e);
}

// Friend functions.

ExampleGroup* describe(string desc, function<void()> spec) {
  ExampleGroup* example_group = new ExampleGroup(desc);

  if (!groups_being_defined.empty()) {
    ExampleGroup* current_group = groups_being_defined.top();
    current_group->addChild(example_group);
  }

  groups_being_defined.push(example_group);
  spec();
  groups_being_defined.pop();

  return example_group;
}

ExampleGroup* context(string desc, function<void()> spec) {
  return describe(desc, spec);
}

}  // namespace core
}  // namespace ccspec
