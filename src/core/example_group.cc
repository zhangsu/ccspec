#include <functional>
#include <list>
#include <stack>
#include <string>
#include <ccspec/core/example.h>
#include <ccspec/core/example_group.h>
#include <ccspec/core/hooks.h>

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

void ExampleGroup::addBeforeEachHook(Hook hook) {
    before_each_hooks_.push_back(hook);
}

void ExampleGroup::run() const {
    list<Hook> before_each_hooks;
    run(before_each_hooks);
}

// Private methods.

ExampleGroup::ExampleGroup(string desc) : desc_(desc) {}

void ExampleGroup::addChild(const ExampleGroup* example_group) {
    children_.push_back(example_group);
}

void ExampleGroup::run(list<Hook>& before_each_hooks) const {
    auto first_new_before_each = before_each_hooks.insert(
        before_each_hooks.end(),
        before_each_hooks_.begin(),
        before_each_hooks_.end()
    );
    for (auto const& example : examples_) {
        for (auto hook : before_each_hooks)
            hook();
        example.run();
    }
    for (auto child : children_)
        child->run(before_each_hooks);
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
