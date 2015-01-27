#ifndef CCSPEC_MATCHERS_BE_SOMETHING_H_
#define CCSPEC_MATCHERS_BE_SOMETHING_H_

#include <functional>
#include <sstream>
#include <string>
#include <ccspec/matcher.h>
#include "be.h"
#include "be_compared_to.h"

// Interface.

namespace ccspec {
namespace matchers {

class BeSomething {
  public:
    static const BeSomething& instance();

    template <typename T>
    Be<T> operator ()(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator <(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator <=(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator >(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator >=(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator ==(const T& expected_value) const;
    template <typename T>
    BeComparedTo<T> operator !=(const T& expected_value) const;

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

template <typename T>
BeComparedTo<T> BeSomething::operator <(const T& expected_value) const {
    return BeComparedTo<T>(std::less<T>(), "<", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator <=(const T& expected_value) const {
    return BeComparedTo<T>(std::less_equal<T>(), "<=", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator >(const T& expected_value) const {
    return BeComparedTo<T>(std::greater<T>(), ">", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator >=(const T& expected_value) const {
    return BeComparedTo<T>(std::greater_equal<T>(), ">=", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator ==(const T& expected_value) const {
    return BeComparedTo<T>(std::equal_to<T>(), "equal", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator !=(const T& expected_value) const {
    return BeComparedTo<T>(std::not_equal_to<T>(), "not equal",
                           expected_value);
}

} // namespace matchers
} // namespace ccspec

#endif // CCSPEC_MATCHERS_BE_SOMETHING_H_
