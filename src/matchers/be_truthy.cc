#include <ccspec/matchers/be_truthy.h>

namespace ccspec {
namespace matchers {

// Public methods.

std::string BeTruthy::desc() const {
    std::ostringstream s;
    s << "should be truthy";
    return s.str();
}

// Private methods.

BeTruthy::BeTruthy() {}

// Friend functions.

BeTruthy be_truthy() {
    return BeTruthy();
}

} // namespace matchers
} // namespace ccspec


