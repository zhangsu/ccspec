#include <functional>
#include <ccspec/core/example.h>
#include <ccspec/core/example_group.h>

namespace ccspec {
namespace core {

using std::function;
using std::string;

// Public methods.

void Example::run() {
    spec_();
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
