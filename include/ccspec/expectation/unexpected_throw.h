#ifndef CCSPEC_UNEXPECTED_THROW_H_
#define CCSPEC_UNEXPECTED_THROW_H_

#include <exception>
#include <string>
#include "exception.h"

namespace ccspec {
namespace expectation {

class UnexpectedThrow : public Exception {
  public:
    explicit UnexpectedThrow(const std::exception& cause);

  private:
    std::string desc(const std::exception& cause);
};

} // namespace expectation
} // namespace ccspec

#endif // CCSPEC_UNEXPECTED_THROW_H_
