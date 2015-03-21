#ifndef INCLUDE_CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
#define INCLUDE_CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_

#include <ostream>
#include <string>

#include "ccspec/core/execution_result.h"
#include "ccspec/core/formatters/text_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

class ProgressFormatter : public TextFormatter {
 public:
  explicit ProgressFormatter(std::ostream&);

  void examplePassed(std::string desc, const ExecutionResult&) const override;
  void exampleFailed(std::string desc, const ExecutionResult&) const override;
  void startDump() const override;
};

}  // namespace formatters
}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
