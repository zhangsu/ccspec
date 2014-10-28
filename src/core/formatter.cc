#include <exception>
#include <ostream>
#include <ccspec/core/example.h>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {

using std::exception;
using std::ostream;

Formatter::Formatter(ostream& output) : output_(output) {}

void Formatter::examplePassed(const Example& example) const {
    (void) example;
}

void Formatter::exampleFailed(const Example& example,
                              const exception& exception) const {
    (void) example;
    (void) exception;
}

} // namespace core
} // namespace ccspec
