#include <exception>
#include <ostream>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception;
using std::ostream;

Formatter::Formatter(ostream& output) : output_(output) {}

void Formatter::examplePassed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

void Formatter::exampleFailed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

} // namespace core
} // namespace ccspec