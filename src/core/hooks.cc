#include <string>
#include <ccspec/core/hooks.h>
#include <ccspec/core/example_group.h>

namespace ccspec {
namespace core {

void before(std::string scope, Hook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (scope == "each" || scope == "example")
        parent_group->addBeforeEachHook(hook);
    else if (scope == "all" || scope == "context")
        parent_group->addBeforeAllHook(hook);
    else
        throw "no such before hook type";
}

void after(std::string scope, Hook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (scope == "each" || scope == "example")
        parent_group->addAfterEachHook(hook);
    else if (scope == "all" || scope == "context")
        parent_group->addAfterAllHook(hook);
    else
        throw "no such before hook type";
}

} // namespace core
} // namespace ccspec

