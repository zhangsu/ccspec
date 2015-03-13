#include <ccspec/core/hooks.h>
#include <ccspec/core/example_group.h>

namespace ccspec {
namespace core {

using std::string;

void before(string scope, BeforeHook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (scope == "each" || scope == "example")
        parent_group->addBeforeEachHook(hook);
    else if (scope == "all" || scope == "context")
        parent_group->addBeforeAllHook(hook);
    else
        throw "no such before hook type";
}

void after(string scope, AfterHook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (scope == "each" || scope == "example")
        parent_group->addAfterEachHook(hook);
    else if (scope == "all" || scope == "context")
        parent_group->addAfterAllHook(hook);
    else
        throw "no such after hook type";
}

void around(string scope, AroundHook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (scope == "each" || scope == "example")
        parent_group->addAroundHook(hook);
    else
        throw "no such around hook type";
}

}  // namespace core
}  // namespace ccspec
