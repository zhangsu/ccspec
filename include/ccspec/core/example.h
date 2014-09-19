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
    void run(const std::list<Hook>* before_each_hooks,
             const std::list<Hook>* after_each_hooks,
             std::list<AroundHook>) const;

  private:
    typedef Example Creator(std::string desc, std::function<void ()> spec);

    Example(std::string desc, std::function<void ()> spec);

    const std::string desc_;
    const std::function<void ()> spec_;
    // These members are marked mutable becuase they are only used to implement
    // the special DSL used for around hooks. Users call the nullary `run`
    // function on the example in around hooks, so all the hooks needed for
    // each example need to be stored as member when the non-nullary `run`
    // function is called (by ExampleGroup). These are not really state
    // maintained by Example but rather by ExampleGroup, so functions like
    // `run` can still be const functions while using them.
    //
    // `around_hooks_` need to be a copy because the `run` method modifies it
    // across different calls whereas the before and after each hooks can be
    // pointers to the original (constant) list passed by ExampleGroup.
    mutable std::list<AroundHook> around_hooks_;
    mutable const std::list<Hook>* before_each_hooks_;
    mutable const std::list<Hook>* after_each_hooks_;

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
