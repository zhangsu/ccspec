#include <functional>
#include <list>
#include <stack>
#include <string>
#include <ccspec/core/example.h>
#include <ccspec/core/example_group.h>
#include <ccspec/core/hooks.h>
#include <ccspec/core/reporter.h>

namespace ccspec {
namespace core {

using std::list;
using std::function;
using std::stack;
using std::string;

stack<ExampleGroup*> groups_being_defined;

// Public methods.

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

void ExampleGroup::run(const Reporter& reporter) const {
    list<BeforeHook> before_each_hooks;
    list<AfterHook> after_each_hooks;
    list<AroundHook> around_hooks;
    run(reporter, before_each_hooks, after_each_hooks, around_hooks);
}

// Private methods.

ExampleGroup::ExampleGroup(string desc) : desc_(desc) {}

void ExampleGroup::addChild(const ExampleGroup* example_group) {
    children_.push_back(example_group);
}

void ExampleGroup::run(const Reporter& reporter,
                       list<BeforeHook>& before_each_hooks,
                       list<AfterHook>& after_each_hooks,
                       list<AroundHook>& around_hooks) const {
    auto first_new_before_each = before_each_hooks.insert(
        before_each_hooks.end(),
        before_each_hooks_.begin(),
        before_each_hooks_.end()
    );
    auto first_new_after_each = after_each_hooks.insert(
        after_each_hooks.end(),
        after_each_hooks_.begin(),
        after_each_hooks_.end()
    );
    auto first_new_around = around_hooks.insert(
        around_hooks.end(),
        around_hooks_.begin(),
        around_hooks_.end()
    );
    for (auto hook : before_all_hooks_)
        hook();
    for (auto const& example : examples_) {
        example.run(&reporter, &before_each_hooks, &after_each_hooks,
                    around_hooks);
    }
    for (auto child : children_)
        child->run(reporter, before_each_hooks, after_each_hooks, around_hooks);
    for (auto hook : after_all_hooks_)
        hook();
    around_hooks.erase(first_new_around, around_hooks.end());
    after_each_hooks.erase(first_new_after_each, after_each_hooks.end());
    before_each_hooks.erase(first_new_before_each, before_each_hooks.end());
}

// Friend methods.

ExampleGroup* describe(string desc, function<void ()> spec) {
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

ExampleGroup* context(string desc, function<void ()> spec) {
    return describe(desc, spec);
}

} // namespace core
} // namespace ccspec
