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
    return "be truthy";
}

// Private methods.

BeTruthy::BeTruthy() {}

}  // namespace matchers
}  // namespace ccspec
