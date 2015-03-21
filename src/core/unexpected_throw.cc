#include "ccspec/core/unexpected_throw.h"

namespace ccspec {
namespace core {

using std::exception;
using std::string;
using ccspec::support::Exception;

// Public methods.

UnexpectedThrow::UnexpectedThrow(const exception& cause)
    : Exception(desc(cause)) {}

// Private methods.

string UnexpectedThrow::desc(const exception& cause) {
  return string("Unexpected exception: ") + cause.what();
}

}  // namespace core
}  // namespace ccspec
