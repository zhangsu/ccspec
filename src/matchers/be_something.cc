#include <ccspec/matchers/be_something.h>

namespace ccspec {
namespace matchers {

const BeSomething& be = BeSomething::instance();

const BeSomething& BeSomething::instance() {
    static BeSomething instance;
    return instance;
}

BeSomething::BeSomething() {}

} // namespace matchers
} // namespace ccspec
