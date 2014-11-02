#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include <exception>
#include <vector>
#include "execution_result.h"
#include "formatter.h"

namespace ccspec {
namespace core {

class Reporter {
  public:
    explicit Reporter(const Formatter*);
    explicit Reporter(const std::vector<const Formatter*> formatters);

    void examplePassed(const ExecutionResult&) const;
    void exampleFailed(const ExecutionResult&) const;

  private:
    const std::vector<const Formatter*> formatters_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
