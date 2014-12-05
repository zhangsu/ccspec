#ifndef CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_
#define CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_

#include <exception>
#include <list>
#include <ostream>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

class TextFormatter : public Formatter {
  public:
    virtual void afterEachHookFailed(std::exception_ptr failure) const;
    virtual void aroundHookFailed(std::exception_ptr failure) const;
    virtual void dumpFailures(
        const std::list<std::exception_ptr>& failures) const;

  protected:
    explicit TextFormatter(std::ostream&);

  private:
    void outputException(std::exception_ptr failure) const;
};

} // namespace formatters
} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_
