#ifndef CCSPEC_CORE_EXAMPLE_GROUP_H_
#define CCSPEC_CORE_EXAMPLE_GROUP_H_

#include <functional>
#include <list>
#include <stack>
#include <string>

namespace ccspec {
namespace core {

class ExampleGroup;

typedef ExampleGroup* Creator(std::string desc, std::function<void ()> spec);

class ExampleGroup {
  public:
    virtual ~ExampleGroup();

    void addChild(ExampleGroup*);

  protected:
    ExampleGroup(std::string desc);

  private:
    std::string desc_;
    std::list<ExampleGroup*> children_;

    friend Creator describe;
    friend Creator context;
};

extern std::stack<ExampleGroup*> groups_being_defined;

Creator describe;
Creator context;

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_EXAMPLE_GROUP_H_
