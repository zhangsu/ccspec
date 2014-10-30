#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include <exception>
#include "execution_result.h"

namespace ccspec {
namespace core {

class Reporter {
  public:
    void examplePassed(const ExecutionResult&) const;
    void exampleFailed(const ExecutionResult&) const;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
