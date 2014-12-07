#include <iostream>
#include <ccspec/core/formatters/text_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::endl;
using std::exception;
using std::exception_ptr;
using std::list;
using std::ostream;
using std::rethrow_exception;

// Public methods.

void TextFormatter::afterEachHookFailed(exception_ptr failure) const {
    output_ << "An error occurred in an `after(:example)` hook" << endl;
    outputException(failure);
}

void TextFormatter::aroundHookFailed(exception_ptr failure) const {
    output_ << "An error occurred in an `around(:example)` hook" << endl;
    outputException(failure);
}

void TextFormatter::dumpFailures(const list<exception_ptr>& failures) const {
    output_ << "Failures:" << endl;
    for (auto failure : failures)
        outputException(failure);
}

// Protected methods.

TextFormatter::TextFormatter(ostream& output) : Formatter(output) {}

// Private methods.

void TextFormatter::outputException(exception_ptr failure) const {
    try {
        rethrow_exception(failure);
    } catch (const exception& e) {
        output_ << e.what() << endl;
    }
}

} // namespace formatters
} // namespace core
} // namespace ccspec
