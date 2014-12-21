#include <ccspec/core/formatters/progress_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::ostream;
using std::string;

// Public methods.

ProgressFormatter::ProgressFormatter(ostream& output) : TextFormatter(output) {}

void ProgressFormatter::examplePassed(string, const ExecutionResult&) const {
    output_ << '.';
}

void ProgressFormatter::exampleFailed(string, const ExecutionResult&) const {
    output_ << 'F';
}

void ProgressFormatter::startDump() const {
    output_ << '\n';
}

} // namespace formatters
} // namespace core
} // namespace ccspec
