#include <ccspec/core/example.h>
#include <ccspec/core/example_group.h>
#include <ccspec/core/unexpected_throw.h>
#include <ccspec/support/exception.h>

namespace ccspec {
namespace core {

using std::current_exception;
using std::make_exception_ptr;
using std::exception;
using std::exception_ptr;
using std::function;
using std::list;
using std::string;
using ccspec::core::UnexpectedThrow;

// Public methods.

// This function enables chaining of around hooks. Callers call this function
// inside each around hook (lambda function), then this function calls the next
// around hook in the chain.
//
// Since this function is nullary, in order to remember the state of which
// around hook to execute next, the around hooks need to be stored in a member
// variable `around_hooks_`. This also implies that `around_hooks_` must be
// mutated in this function in order to transition to the next state.
void Example::run() const {
    if (reporter_ == nullptr ||
        before_each_hooks_ == nullptr ||
        after_each_hooks_ == nullptr ||
        execution_result_ == nullptr) {
        // The required pointers should have been initialized by the overloaded
        // run function before this function is called.
        return;
    }

    if (around_hooks_.empty()) {
        catchException(
            [this] {
                for (auto hook : *before_each_hooks_)
                    hook();
                spec_();
            },
            // Save errors in before hook and example.
            [&](exception_ptr e) { execution_result_->set_exception(e); }
        );
        // Continue running after each hooks regardless of execution result.
        catchException(
            [this] {
                for (auto hook : *after_each_hooks_)
                    hook();
            },
            [&](exception_ptr e) {
                if (execution_result_->exception()) {
                    // An error happened in a before hook or an example but
                    // another is happening here in an after hook, report
                    // separately.
                    reporter_->afterEachHookFailed(e);
                } else {
                    execution_result_->set_exception(e);
                }
            }
        );
    } else {
        AroundHook around_hook = around_hooks_.front();
        around_hooks_.pop_front();
        around_hook(*this);
    }
}

// Errors in around hooks are handled here so that only one error is caught
// in a chain of around hooks.
void Example::run(Reporter* reporter,
                  const list<BeforeHook>* before_each_hooks,
                  const list<AfterHook>* after_each_hooks,
                  list<AroundHook> around_hooks) const {
    reporter_ = reporter;
    before_each_hooks_ = before_each_hooks;
    after_each_hooks_ = after_each_hooks;
    around_hooks_ = around_hooks;
    ExecutionResult execution_result;
    execution_result_ = &execution_result;

    catchException(
        [this] { run(); },
        [&](exception_ptr e) {
            if (execution_result_->exception()) {
                // An error happened in a before hook, an example or an
                // after hook but another is happening here in an around
                // hook, report separately.
                reporter->aroundHookFailed(e);
            } else {
                execution_result.set_exception(e);
            }
        }
    );
    finish(execution_result);

    reporter_ = nullptr;
    before_each_hooks_ = nullptr;
    after_each_hooks_ = nullptr;
    around_hooks_.clear();
    execution_result_ = nullptr;
}

// Private methods.

Example::Example(string desc, function<void ()> spec)
    : desc_(desc),
      spec_(spec),
      reporter_(nullptr),
      before_each_hooks_(nullptr),
      after_each_hooks_(nullptr) {}

void Example::catchException(
    function<void()> func,
    function<void(exception_ptr)> handleException
) const {
    try {
        func();
    } catch (const ccspec::support::Exception& e) {
        // The exception can only be a Mismatch as no other CCSpec
        // exceptions should be thrown inside the spec code.
        handleException(current_exception());
    } catch (const exception& e) {
        handleException(make_exception_ptr(UnexpectedThrow(e)));
    }
}

void Example::finish(const ExecutionResult& execution_result) const {
    if (execution_result.exception())
        reporter_->exampleFailed(execution_result);
    else
        reporter_->examplePassed(execution_result);
}

// Friend functions.

Example it(string desc, function<void ()> spec) {
    Example example = Example(desc, spec);
    ExampleGroup* parent_group = groups_being_defined.top();
    parent_group->addExample(example);
    return example;
}

Example example(string desc, function<void ()> spec) {
    return it(desc, spec);
}

Example specify(string desc, function<void ()> spec) {
    return it(desc, spec);
}

} // namespace core
} // namespace ccspec
