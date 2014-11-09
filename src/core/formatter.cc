#include <exception>
#include <list>
#include <ostream>
#include <ccspec/core/execution_result.h>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception;
using std::list;
using std::ostream;

// public methods.

void Formatter::examplePassed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

void Formatter::exampleFailed(const ExecutionResult& execution_result) const {
    (void) execution_result;
}

void Formatter::startDump() const {}

void Formatter::dumpFailures(list<const exception*> failures) const {
    (void) failures;
}

// Protected methods.

Formatter::Formatter(ostream& output) : output_(output) {}

} // namespace core
} // namespace ccspec
