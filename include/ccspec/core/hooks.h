#ifndef CCSPEC_CORE_HOOKS_H_
#define CCSPEC_CORE_HOOKS_H_

#include <functional>
#include <string>

namespace ccspec {
namespace core {

class Example;

typedef std::function<void ()> BeforeHook;
typedef std::function<void ()> AfterHook;
typedef std::function<void (const Example&)> AroundHook;

void before(std::string scope, BeforeHook);
void after(std::string scope, AfterHook);
void around(std::string scope, AroundHook);

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_HOOKS_H_
