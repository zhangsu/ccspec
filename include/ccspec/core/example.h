#ifndef CCSPEC_CORE_EXAMPLE_H_
#define CCSPEC_CORE_EXAMPLE_H_

#include <functional>
#include <list>
#include <string>
#include "hooks.h"

namespace ccspec {
namespace core {

class Example {
  public:
    void run() const;
    void run(std::list<AroundHook>) const;

  private:
    typedef Example Creator(std::string desc, std::function<void ()> spec);

    Example(std::string desc, std::function<void ()> spec);

    const std::string desc_;
    const std::function<void ()> spec_;
    mutable std::list<AroundHook> around_hooks_;

    friend Creator it;
    friend Creator example;
    friend Creator specify;
};

Example::Creator it;
Example::Creator example;
Example::Creator specify;

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_EXAMPLE_H_
