#include <exception>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/formatters/progress_formatter.h>
#include <ccspec/core/formatters/text_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::exception;
using std::ostream;

ProgressFormatter::ProgressFormatter(ostream& output) : TextFormatter(output) {}

void ProgressFormatter::examplePassed(const ExecutionResult& execution_result)
    const {
    (void) execution_result;
}

void ProgressFormatter::exampleFailed(const ExecutionResult& execution_result)
    const {
    (void) execution_result;
}

} // namespace formatters
} // namespace core
} // namespace ccspec
