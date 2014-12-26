#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception_ptr;
using std::list;
using std::ostream;
using std::string;

// public methods.

void Formatter::exampleGroupStarted(string) {}

void Formatter::exampleGroupFinished(string) {}

void Formatter::examplePassed(string, const ExecutionResult&) const {}

void Formatter::exampleFailed(string, const ExecutionResult&) const {}

void Formatter::afterEachHookFailed(exception_ptr) const {}

void Formatter::afterAllHookFailed(exception_ptr) const {}

void Formatter::aroundHookFailed(exception_ptr) const {}

void Formatter::startDump() const {}

void Formatter::dumpFailures(const list<exception_ptr>&) const {}

// Protected methods.

Formatter::Formatter(ostream& output) : output_(output) {}

Formatter::~Formatter() {}

ostream& Formatter::output() const {
    return output_;
}

} // namespace core
} // namespace ccspec
