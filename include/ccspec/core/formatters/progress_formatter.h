#ifndef CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
#define CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_

#include <exception>
#include <ccspec/core/example.h>
#include "text_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

class ProgressFormatter : public TextFormatter {
  public:
    void examplePassed(const Example&) const;
    void exampleFailed(const Example&, const std::exception&) const;
};

} // namespace formatters
} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTERS_PROGRESS_FORMATTER_H_
