#ifndef CCSPEC_CORE_HOOKS_H_
#define CCSPEC_CORE_HOOKS_H_

#include <functional>
#include <string>

namespace ccspec {
namespace core {

class Example;

typedef std::function<void ()> Hook;
typedef std::function<void (const Example&)> AroundHook;

void before(std::string scope, Hook hook);
void after(std::string scope, Hook hook);
void around(std::string scope, AroundHook hook);

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_HOOKS_H_

