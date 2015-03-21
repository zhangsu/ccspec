#include "ccspec/core/execution_result.h"

namespace ccspec {
namespace core {

using std::exception_ptr;

// Public methods.

ExecutionResult::ExecutionResult() : exception_(nullptr) {}

exception_ptr ExecutionResult::exception() const {
  return exception_;
}

void ExecutionResult::set_exception(exception_ptr exception) {
  exception_ = exception;
}

}  // namespace core
}  // namespace ccspec
