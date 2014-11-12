#include <string>
#include <ccspec/expectation/exception.h>

namespace ccspec {
namespace expectation {

using std::string;

// Public methods.

const char* Exception::what() const noexcept {
    return desc().c_str();
}

const std::string& Exception::desc() const {
    return desc_;
}

// Protected methods.

Exception::Exception(string desc) : desc_(desc) {}

} // namespace expectation
} // namespace ccspec
