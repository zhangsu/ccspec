#include <ccspec/expectation/unexpected_throw.h>

namespace ccspec {
namespace expectation {

UnexpectedThrow::UnexpectedThrow(const std::exception& cause)
    : cause_(cause) {}

} // namespace expectation
} // namespace ccspec
