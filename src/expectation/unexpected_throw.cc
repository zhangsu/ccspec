#include <string>
#include <ccspec/expectation/unexpected_throw.h>

namespace ccspec {
namespace expectation {

using std::exception;
using std::string;

// Public methods.

UnexpectedThrow::UnexpectedThrow(const exception& cause)
    : Exception(desc(cause)) {}

// Private methods.

std::string UnexpectedThrow::desc(const std::exception& cause) {
    return string("Unexpected exception: ") + cause.what();
}

} // namespace expectation
} // namespace ccspec
