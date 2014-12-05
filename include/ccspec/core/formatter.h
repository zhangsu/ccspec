#ifndef CCSPEC_CORE_FORMATTER_H_
#define CCSPEC_CORE_FORMATTER_H_

#include <exception>
#include <list>
#include <ostream>
#include "execution_result.h"

namespace ccspec {
namespace core {

class Formatter {
  public:
    virtual void examplePassed(const ExecutionResult&) const;
    virtual void exampleFailed(const ExecutionResult&) const;
    virtual void afterEachHookFailed(std::exception_ptr failure) const;
    virtual void aroundHookFailed(std::exception_ptr failure) const;
    virtual void startDump() const;
    virtual void dumpFailures(
        const std::list<std::exception_ptr>& failures) const;

  protected:
    explicit Formatter(std::ostream&);

    std::ostream& output_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTER_H_
