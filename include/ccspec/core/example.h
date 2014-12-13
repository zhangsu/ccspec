#ifndef CCSPEC_CORE_EXAMPLE_H_
#define CCSPEC_CORE_EXAMPLE_H_

#include <functional>
#include <list>
#include <string>
#include "execution_result.h"
#include "hooks.h"
#include "reporter.h"

namespace ccspec {
namespace core {

class Example {
  public:
    void run() const;
    void run(Reporter*,
             const std::list<BeforeHook>* before_each_hooks,
             const std::list<AfterHook>* after_each_hooks,
             std::list<AroundHook>) const;

  private:
    typedef Example Creator(std::string desc, std::function<void ()> spec);

    Example(std::string desc, std::function<void ()> spec);

    void finish(const ExecutionResult&) const;

    const std::string desc_;
    const std::function<void ()> spec_;
    // These members are marked mutable becuase they are only used to implement
    // the special DSL used for around hooks. Users call the nullary `run`
    // method on the example in around hooks, so all the hooks needed for
    // each example need to be stored as member when the non-nullary `run`
    // method is called (by ExampleGroup). These are not really state
    // maintained by Example but rather by ExampleGroup, so methods like
    // `run` can still be const methods while using them. If not for
    // implementing the DSL, they would be passed-in as arguments to the `run`
    // method and can thus be mutated in a const `run` method. They should only
    // be mutated in the run methods.
    //
    // `around_hooks_` need to be a copy because the `run` method modifies it
    // across different calls whereas other members can be pointers to the
    // original constants passed by ExampleGroup.
    mutable std::list<AroundHook> around_hooks_;
    mutable Reporter* reporter_;
    mutable const std::list<BeforeHook>* before_each_hooks_;
    mutable const std::list<AfterHook>* after_each_hooks_;
    mutable ExecutionResult* execution_result_;

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
