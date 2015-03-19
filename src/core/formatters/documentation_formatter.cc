#include "ccspec/core/formatters/documentation_formatter.h"

namespace ccspec {
namespace core {
namespace formatters {

using std::endl;
using std::ostream;
using std::string;

// Public methods.

DocumentationFormatter::DocumentationFormatter(ostream& output)
    : TextFormatter(output),
      group_level_(0) {}

void DocumentationFormatter::exampleGroupStarted(string desc) {
    if (group_level_ == 0)
        output() << endl;

    printIndentation();
    output() << desc << endl;
    group_level_++;
}

void DocumentationFormatter::exampleGroupFinished(string) {
    group_level_--;
}

void DocumentationFormatter::examplePassed(
    string desc,
    const ExecutionResult&
) const {
    printIndentation();
    output() << desc << endl;
}

void DocumentationFormatter::exampleFailed(
    string desc,
    const ExecutionResult&
) const {
    printIndentation();
    output() << desc << " (FAILED) " << endl;
}

// Private methods.

void DocumentationFormatter::printIndentation() const {
    for (int i = 0; i < group_level_; ++i)
        output() << "  ";
}

}  // namespace formatters
}  // namespace core
}  // namespace ccspec
