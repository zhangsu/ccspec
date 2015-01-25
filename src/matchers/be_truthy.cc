#include <ccspec/matchers/be_truthy.h>

namespace ccspec {
namespace matchers {

const BeTruthy& be_truthy = BeTruthy::instance();

// Public methods.

const BeTruthy& BeTruthy::instance() {
    static BeTruthy instance;
    return instance;
}

std::string BeTruthy::desc() const {
    std::ostringstream s;
    s << "should be truthy";
    return s.str();
}

// Private methods.

BeTruthy::BeTruthy() {}

} // namespace matchers
} // namespace ccspec


