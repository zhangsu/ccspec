#ifndef CCSPEC_CORE_EXAMPLE_H_
#define CCSPEC_CORE_EXAMPLE_H_

#include <functional>
#include <string>

namespace ccspec {
namespace core {

class Example {
  public:
    void run() const;

  private:
    typedef Example Creator(std::string desc, std::function<void ()> spec);

    Example(std::string desc, std::function<void ()> spec);

    const std::string desc_;
    const std::function<void ()> spec_;

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
