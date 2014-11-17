#include <exception>
#include <list>
#include <ostream>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception_ptr;
using std::list;
using std::ostream;

// public methods.

void Formatter::examplePassed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

void Formatter::exampleFailed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

void Formatter::afterEachHookFailed(exception_ptr failure) const {
    (void) failure;
}

void Formatter::startDump() const {}

void Formatter::dumpFailures(const list<exception_ptr>& failures) const {
    (void) failures;
}

// Protected methods.

Formatter::Formatter(ostream& output) : output_(output) {}

} // namespace core
} // namespace ccspec
