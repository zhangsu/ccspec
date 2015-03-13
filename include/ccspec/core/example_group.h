#ifndef CCSPEC_CORE_EXAMPLE_GROUP_H_
#define CCSPEC_CORE_EXAMPLE_GROUP_H_

#include <exception>
#include <functional>
#include <list>
#include <stack>
#include <string>
#include "example.h"
#include "hooks.h"
#include "reporter.h"

namespace ccspec {
namespace core {

class ExampleGroup;

extern std::stack<ExampleGroup*> groups_being_defined;

class ExampleGroup {
  public:
    virtual ~ExampleGroup();

    static void catchException(
        std::function<void()> func,
        std::function<void(std::exception_ptr)> handleException);

    void addExample(Example);
    void addBeforeEachHook(BeforeHook);
    void addBeforeAllHook(BeforeHook);
    void addAfterEachHook(AfterHook);
    void addAfterAllHook(AfterHook);
    void addAroundHook(AroundHook);
    bool run(Reporter&) const;

  private:
    typedef ExampleGroup* Creator(std::string desc,
                                  std::function<void ()> spec);

    explicit ExampleGroup(std::string desc);

    void addChild(const ExampleGroup*);
    bool run(Reporter&,
             std::list<BeforeHook>& before_each_hooks,
             std::list<AfterHook>& after_each_hooks,
             std::list<AroundHook>&) const;
    void failWithException(Reporter&, std::exception_ptr) const;

    const std::string desc_;
    std::list<const ExampleGroup*> children_;
    std::list<Example> examples_;
    std::list<BeforeHook> before_each_hooks_;
    std::list<BeforeHook> before_all_hooks_;
    std::list<AfterHook> after_each_hooks_;
    std::list<AfterHook> after_all_hooks_;
    std::list<AroundHook> around_hooks_;

    friend Creator describe;
    friend Creator context;
};

ExampleGroup::Creator describe;
ExampleGroup::Creator context;

}  // namespace core
}  // namespace ccspec

#endif // CCSPEC_CORE_EXAMPLE_GROUP_H_
