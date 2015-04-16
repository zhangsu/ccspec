#ifndef INCLUDE_CCSPEC_MATCHERS_BE_SOMETHING_H_
#define INCLUDE_CCSPEC_MATCHERS_BE_SOMETHING_H_

#include <functional>
#include <sstream>
#include <string>

#include "ccspec/matcher.h"
#include "ccspec/matchers/be.h"
#include "ccspec/matchers/be_compared_to.h"

// Interface.

namespace ccspec {
namespace matchers {

// Creates various matchers that have their DSL start with "be".
class BeSomething {
 public:
  // Returns the singleton of BeSomething.
  static const BeSomething& instance();

  // Creates a Be matcher that matches if the actual value has the same object
  // identity as the expected value.
  template <typename T>
  Be<T> operator ()(const T& expected_value) const;

  // Creates a "less than" matcher that matches if the actual value is less than
  // the expected value.
  template <typename T>
  BeComparedTo<T> operator <(const T& expected_value) const;

  // Creates a "less than or equal to" matcher that matches if the actual value
  // is less than or equal to the expected value.
  template <typename T>
  BeComparedTo<T> operator <=(const T& expected_value) const;

  // Creates a "greater than" matcher that matches if the actual value is
  // greater than the expected value.
  template <typename T>
  BeComparedTo<T> operator >(const T& expected_value) const;

  // Creates a "greater than or equal to" matcher that matches if the actual
  // value is greater than or equal to the expected value.
  template <typename T>
  BeComparedTo<T> operator >=(const T& expected_value) const;

  // Creates a "equal to" matcher that matches if the actual value is equal to
  // the expected value.
  template <typename T>
  BeComparedTo<T> operator ==(const T& expected_value) const;

  // Creates a "not equal to" matcher that matches if the actual value is not
  // equal to the expected value.
  template <typename T>
  BeComparedTo<T> operator !=(const T& expected_value) const;

 private:
  BeSomething() = default;
  // Deletes copy constructor and assignment operator to maintain singleton
  // property.
  BeSomething(const BeSomething&) = delete;
  void operator =(const BeSomething&) = delete;
};

// Points to the BeSomething singleton.
extern const BeSomething& be;

}  // namespace matchers
}  // namespace ccspec

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
  return BeComparedTo<T>(std::equal_to<T>(), "equal to", expected_value);
}

template <typename T>
BeComparedTo<T> BeSomething::operator !=(const T& expected_value) const {
  return BeComparedTo<T>(std::not_equal_to<T>(), "not equal to",
                         expected_value);
}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_BE_SOMETHING_H_
