#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include <exception>
#include <list>
#include <string>
#include <vector>
#include "execution_result.h"
#include "formatter.h"

namespace ccspec {
namespace core {

class Reporter {
  public:
    explicit Reporter(Formatter*);
    explicit Reporter(std::vector<Formatter*> formatters);
    ~Reporter();

    void exampleGroupStarted(std::string desc) const;
    void exampleGroupFinished(std::string desc) const;
    void examplePassed(std::string desc, const ExecutionResult&);
    void exampleFailed(std::string desc, const ExecutionResult&);
    void afterEachHookFailed(std::exception_ptr failure);
    void afterAllHookFailed(std::exception_ptr failure);
    void aroundHookFailed(std::exception_ptr failure);

  private:
    void finish() const;

    const std::vector<Formatter*> formatters_;
    std::list<std::exception_ptr> failures_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
