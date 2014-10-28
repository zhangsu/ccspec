#include <exception>
#include <ccspec/core/example.h>
#include <ccspec/core/formatter.h>
#include <ccspec/core/formatters/progress_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::exception;

void ProgressFormatter::examplePassed(const Example& example) const {
    (void) example;
}

void ProgressFormatter::exampleFailed(const Example& example,
                                      const exception& exception) const {
    (void) example;
    (void) exception;
}

} // namespace formatters
} // namespace core
} // namespace ccspec
