#include <string>
#include <ccspec/expectation/unexpected_throw.h>

namespace ccspec {
namespace expectation {

using std::string;

UnexpectedThrow::UnexpectedThrow(const std::exception& cause)
    : cause_(cause) {}

string UnexpectedThrow::toString() {
    return string("Unexpected exception: ") + cause_.what();
}

} // namespace expectation
} // namespace ccspec
