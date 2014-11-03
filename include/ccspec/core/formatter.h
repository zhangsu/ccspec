#ifndef CCSPEC_CORE_FORMATTER_H_
#define CCSPEC_CORE_FORMATTER_H_

#include <exception>
#include <ostream>
#include "execution_result.h"

namespace ccspec {
namespace core {

class Formatter {
  public:
    virtual void examplePassed(const ExecutionResult&) const;
    virtual void exampleFailed(const ExecutionResult&) const;

  protected:
    explicit Formatter(std::ostream&);

    std::ostream& output_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTER_H_
