#ifndef INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_
#define INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_

#include <exception>
#include <string>

#include "ccspec/support/exception.h"

namespace ccspec {
namespace core {

class UnexpectedThrow : public ccspec::support::Exception {
 public:
  explicit UnexpectedThrow(const std::exception& cause);

 private:
  std::string desc(const std::exception& cause);
};

}  // namespace core
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_CORE_UNEXPECTED_THROW_H_
