#include <functional>
#include <stack>
#include <string>
#include <ccspec/core/example_group.h>

namespace ccspec {
namespace core {

using std::function;
using std::stack;
using std::string;

stack<ExampleGroup*> groups_being_defined;

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

// Public methods.

ExampleGroup::~ExampleGroup() {
    for (auto it = children_.begin(); it != children_.end(); ++it)
        delete *it;
}

void ExampleGroup::addChild(ExampleGroup* example_group) {
    children_.push_back(example_group);
}

// Protected methods.

ExampleGroup::ExampleGroup(string desc) : desc_(desc) {}

} // namespace core
} // namespace ccspec
