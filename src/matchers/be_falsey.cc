#include "ccspec/matchers/be_falsey.h"

namespace ccspec {
namespace matchers {

const BeFalsey& be_falsey = BeFalsey::instance();

// Public methods.

const BeFalsey& BeFalsey::instance() {
  static BeFalsey instance;
  return instance;
}

std::string BeFalsey::desc() const {
  return "be falsey";
}

// Private methods.

BeFalsey::BeFalsey() {}

}  // namespace matchers
}  // namespace ccspec
