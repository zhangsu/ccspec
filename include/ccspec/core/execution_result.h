#ifndef INCLUDE_CCSPEC_CORE_EXECUTION_RESULT_H_
#define INCLUDE_CCSPEC_CORE_EXECUTION_RESULT_H_

#include <exception>

namespace ccspec {
namespace core {

// Stores the execution result of an example.
class ExecutionResult {
 public:
  ExecutionResult();

  // A pointer to an exceptional execution result or the nullptr otherwise.
  std::exception_ptr exception() const;
  void set_exception(std::exception_ptr);

 private:
  std::exception_ptr exception_;
};

}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_EXECUTION_RESULT_H_
