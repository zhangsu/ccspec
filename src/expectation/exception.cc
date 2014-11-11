#include <ccspec/expectation/exception.h>

namespace ccspec {
namespace expectation {

const char* Exception::what() const noexcept {
    return toString().c_str();
}

} // namespace expectation
} // namespace ccspec

