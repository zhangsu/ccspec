#ifndef CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_
#define CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_

#include <ostream>
#include <string>
#include <ccspec/core/execution_result.h>
#include "text_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

class DocumentationFormatter : public TextFormatter {
  public:
    explicit DocumentationFormatter(std::ostream&);

    virtual void exampleGroupStarted(std::string desc);
    virtual void exampleGroupFinished(std::string desc);
    virtual void examplePassed(std::string desc, const ExecutionResult&) const;
    virtual void exampleFailed(std::string desc, const ExecutionResult&) const;

  private:
    void printIndentation() const;

    int group_level_;
};

} // namespace formatters
} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTERS_DOCUMENTATION_FORMATTER_H_
