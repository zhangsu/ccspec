#include <string>
#include <ccspec/core/hooks.h>
#include <ccspec/core/example_group.h>

namespace ccspec {
namespace core {

void before(std::string entity, Hook hook) {
    ExampleGroup* parent_group = groups_being_defined.top();
    if (entity == "each")
        parent_group->addBeforeEachHook(hook);
    else
        throw "no such before hook type";
}

} // namespace core
} // namespace ccspec

