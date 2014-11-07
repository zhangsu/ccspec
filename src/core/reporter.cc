#include <exception>
#include <vector>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/formatter.h>
#include <ccspec/core/reporter.h>

namespace ccspec {
namespace core {

using std::exception;
using std::vector;

// Public methods.

Reporter::Reporter(const Formatter* formatter) : formatters_{formatter} {}

Reporter::Reporter(const vector<const Formatter*> formatters)
    : formatters_(formatters) {}

void Reporter::examplePassed(const ExecutionResult& execution_result) {
    for (auto formatter : formatters_)
        formatter->examplePassed(execution_result);
}

void Reporter::exampleFailed(const ExecutionResult& execution_result) {
    for (auto formatter : formatters_)
        formatter->exampleFailed(execution_result);
    failures_.push_back(execution_result.exception());
}

} // namespace core
} // namespace ccspec
