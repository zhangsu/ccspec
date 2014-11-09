#include <exception>
#include <list>
#include <ostream>
#include <iostream>
#include <ccspec/core/formatter.h>
#include <ccspec/core/formatters/text_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::exception;
using std::list;
using std::ostream;
using std::endl;

// Public methods.

void TextFormatter::dumpFailures(list<const exception*> failures) const {
    output_ << "Failures:" << endl;
    for (auto failure : failures)
        output_ << failure->what() << endl;

}

// Protected methods.

TextFormatter::TextFormatter(ostream& output) : Formatter(output) {}

} // namespace formatters
} // namespace core
} // namespace ccspec
