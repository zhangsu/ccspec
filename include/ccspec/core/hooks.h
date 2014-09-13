#ifndef CCSPEC_CORE_HOOKS_H_
#define CCSPEC_CORE_HOOKS_H_

#include <functional>
#include <string>

namespace ccspec {
namespace core {

typedef std::function<void ()> Hook;

void before(std::string entity, Hook hook);
void after(std::string entity, Hook hook);

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_HOOKS_H_

