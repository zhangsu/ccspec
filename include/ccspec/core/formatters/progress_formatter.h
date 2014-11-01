#ifndef CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
#define CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_

#include <exception>
#include <ostream>
#include <ccspec/core/execution_result.h>
#include "text_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

class ProgressFormatter : public TextFormatter {
  public:
    explicit ProgressFormatter(std::ostream&);

    virtual void examplePassed(const ExecutionResult&) const;
    virtual void exampleFailed(const ExecutionResult&) const;
};

} // namespace formatters
} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
