#ifndef CCSPEC_CORE_EXECUTION_RESULT_H_
#define CCSPEC_CORE_EXECUTION_RESULT_H_

#include <exception>

namespace ccspec {
namespace core {

class ExecutionResult {
  public:
    ExecutionResult();

    const std::exception* exception() const;
    void set_exception(const std::exception*);

  private:
    const std::exception* exception_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_EXECUTION_RESULT_H_
