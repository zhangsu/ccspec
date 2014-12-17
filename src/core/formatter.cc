#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception_ptr;
using std::list;
using std::ostream;

// public methods.

void Formatter::examplePassed(const ExecutionResult&) const {}

void Formatter::exampleFailed(const ExecutionResult&) const {}

void Formatter::afterEachHookFailed(exception_ptr) const {}

void Formatter::afterAllHookFailed(exception_ptr) const {}

void Formatter::aroundHookFailed(exception_ptr) const {}

void Formatter::startDump() const {}

void Formatter::dumpFailures(const list<exception_ptr>&) const {}

// Protected methods.

Formatter::Formatter(ostream& output) : output_(output) {}

} // namespace core
} // namespace ccspec
