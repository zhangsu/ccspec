#include <ccspec/core/formatters/progress_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::ostream;

// Public methods.

ProgressFormatter::ProgressFormatter(ostream& output) : TextFormatter(output) {}

void ProgressFormatter::examplePassed(const ExecutionResult& execution_result)
    const {
    (void) execution_result;

    output_ << '.';
}

void ProgressFormatter::exampleFailed(const ExecutionResult& execution_result)
    const {
    (void) execution_result;

    output_ << 'F';
}

void ProgressFormatter::startDump() const {
    output_ << '\n';
}

} // namespace formatters
} // namespace core
} // namespace ccspec
