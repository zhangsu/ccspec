#include <exception>
#include <ccspec/core/example.h>
#include <ccspec/core/reporter.h>

namespace ccspec {
namespace core {

using std::exception;

void Reporter::examplePassed(const Example& example) const {
}

void Reporter::exampleFailed(const Example& example,
                             const exception& exception) const {
}

} // namespace core
} // namespace ccspec
