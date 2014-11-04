#include <string>
#include <ccspec/expectation/unexpected_throw.h>

namespace ccspec {
namespace expectation {

using std::exception;
using std::string;

// Public methods.

UnexpectedThrow::UnexpectedThrow(const exception& cause)
    : cause_(cause) {}

string UnexpectedThrow::toString() const {
    return string("Unexpected exception: ") + cause_.what();
}

} // namespace expectation
} // namespace ccspec
