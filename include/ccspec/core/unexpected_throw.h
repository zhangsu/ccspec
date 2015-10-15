#ifndef INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_
#define INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_

#include <exception>
#include <string>

#include "ccspec/support/exception.h"

namespace ccspec {
namespace core {

// Signifies unexpected exceptions thrown in CCSpec examples. When this
// exception is thrown by CCSpec, it means that the system under test throws an
// exception that is not expected by the test.
class UnexpectedThrow : public ccspec::support::Exception {
 public:
  // Constructs an UnexpectedThrow exception with the given cause, which is the
  // unexpected exception the system under test originally throws.
  explicit UnexpectedThrow(const std::exception& cause);

 private:
  std::string desc(const std::exception& cause);
};

}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_
