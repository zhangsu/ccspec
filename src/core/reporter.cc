#include <ccspec/core/reporter.h>

namespace ccspec {
namespace core {

using std::exception_ptr;
using std::string;
using std::vector;

// Public methods.

Reporter::Reporter(Formatter* formatter) : formatters_{formatter} {}

Reporter::Reporter(vector<Formatter*> formatters) : formatters_(formatters) {}

Reporter::~Reporter() {
    finish();
}

void Reporter::exampleGroupStarted(string desc) const {
    for (auto formatter : formatters_)
        formatter->exampleGroupStarted(desc);
}

void Reporter::exampleGroupFinished(string desc) const {
    for (auto formatter : formatters_)
        formatter->exampleGroupFinished(desc);
}

void Reporter::examplePassed(
    string desc,
    const ExecutionResult& execution_result
) {
    for (auto formatter : formatters_)
        formatter->examplePassed(desc, execution_result);
}

void Reporter::exampleFailed(
    string desc,
    const ExecutionResult& execution_result
) {
    for (auto formatter : formatters_)
        formatter->exampleFailed(desc, execution_result);
    failures_.push_back(execution_result.exception());
}

void Reporter::afterEachHookFailed(exception_ptr failure) {
    for (auto formatter : formatters_)
        formatter->afterEachHookFailed(failure);
}

void Reporter::afterAllHookFailed(exception_ptr failure) {
    for (auto formatter : formatters_)
        formatter->afterAllHookFailed(failure);
}

void Reporter::aroundHookFailed(exception_ptr failure) {
    for (auto formatter : formatters_)
        formatter->aroundHookFailed(failure);
}

// Private methods.

void Reporter::finish() const {
    for (auto formatter : formatters_) {
        formatter->startDump();
        formatter->dumpFailures(failures_);
    }
}

} // namespace core
} // namespace ccspec
