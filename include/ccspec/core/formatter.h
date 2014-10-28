#ifndef CCSPEC_CORE_FORMATTER_H_
#define CCSPEC_CORE_FORMATTER_H_

#include <exception>
#include <ostream>
#include "example.h"

namespace ccspec {
namespace core {

class Formatter {
  public:
    explicit Formatter(std::ostream&);

    void examplePassed(const Example&) const;
    void exampleFailed(const Example&, const std::exception&) const;

  protected:
    std::ostream& output_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTER_H_
