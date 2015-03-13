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
    output() << "An error occurred in an `after(:example)` hook" << endl;
    outputException(failure);
}

void TextFormatter::afterAllHookFailed(exception_ptr failure) const {
    output() << "An error occurred in an `after(:context)` hook" << endl;
    outputException(failure);
}

void TextFormatter::aroundHookFailed(exception_ptr failure) const {
    output() << "An error occurred in an `around(:example)` hook" << endl;
    outputException(failure);
}

void TextFormatter::dumpFailures(const list<exception_ptr>& failures) const {
    if (failures.empty())
        return;

    output() << endl << "Failures:" << endl;
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
        output() << e.what() << endl;
    }
}

}  // namespace formatters
}  // namespace core
}  // namespace ccspec
