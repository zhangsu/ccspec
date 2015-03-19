#include "ccspec/support/exception.h"

namespace ccspec {
namespace support {

using std::string;

// Public methods.

const char* Exception::what() const noexcept {
    return desc().c_str();
}

const string& Exception::desc() const {
    return desc_;
}

// Protected methods.

Exception::Exception(string desc) : desc_(desc) {}

}  // namespace support
}  // namespace ccspec
