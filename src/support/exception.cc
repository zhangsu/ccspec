#include "ccspec/support/exception.h"

namespace ccspec {
namespace support {

using std::string;

// Public methods.

const char* Exception::what() const noexcept {
  return desc_.c_str();
}

// Protected methods.

Exception::Exception(string desc) : desc_(desc) {}

}  // namespace support
}  // namespace ccspec
