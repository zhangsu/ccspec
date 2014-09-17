#include <functional>
#include <list>
#include <ccspec/core/example.h>
#include <ccspec/core/example_group.h>
#include <ccspec/core/hooks.h>

namespace ccspec {
namespace core {

using std::function;
using std::list;
using std::string;

// Public methods.

void Example::run() const {
    if (around_hooks_.empty()) {
        spec_();
    } else {
        AroundHook around_hook = around_hooks_.front();
        around_hooks_.pop_front();
        around_hook(*this);
    }
}

void Example::run(const list<AroundHook> around_hooks) const {
    around_hooks_ = around_hooks;
    run();
}

// Private methods.

Example::Example(string desc, std::function<void ()> spec)
    : desc_(desc), spec_(spec) {}

// Friend methods.

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
