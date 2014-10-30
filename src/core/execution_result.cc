#include <exception>
#include <ccspec/core/execution_result.h>

namespace ccspec {
namespace core {

ExecutionResult::ExecutionResult()
    : exception_(nullptr) {}

const std::exception* ExecutionResult::exception() const {
    return exception_;
}

void ExecutionResult::set_exception(const std::exception* exception) {
    exception_ = exception;
}

} // namespace core
} // namespace ccspec
