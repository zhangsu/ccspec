#include <exception>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/reporter.h>

namespace ccspec {
namespace core {

using std::exception;
using std::vector;

void Reporter::examplePassed(const ExecutionResult& execution_result) const {
}

void Reporter::exampleFailed(const ExecutionResult& execution_result) const {
}

} // namespace core
} // namespace ccspec
