#ifndef CCSPEC_MATCHERS_BE_SOMETHING_H_
#define CCSPEC_MATCHERS_BE_SOMETHING_H_

#include <sstream>
#include <string>
#include <ccspec/matcher.h>
#include "be.h"

// Interface.

namespace ccspec {
namespace matchers {

class BeSomething {
  public:
    static const BeSomething& instance();

    template <typename T>
    Be<T> operator ()(const T& expected_value) const;

  private:
    BeSomething();
    BeSomething(const BeSomething&) = delete;
    void operator =(const BeSomething&) = delete;
};

extern const BeSomething& be;

} // namespace matchers
} // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename T>
Be<T> BeSomething::operator ()(const T& expected_value) const {
    return Be<T>(expected_value);
}

} // namespace matchers
} // namespace ccspec

#endif // CCSPEC_MATCHERS_BE_SOMETHING_H_
