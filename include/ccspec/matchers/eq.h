#ifndef INCLUDE_CCSPEC_MATCHERS_EQ_H_
#define INCLUDE_CCSPEC_MATCHERS_EQ_H_

#include <sstream>
#include <string>

#include "ccspec/support/inspect.h"
#include "ccspec/unary_matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches expected value with actual value using the equality operator ==.
//
// Example:
//      expect(4).to(eq(4.0));
//      expect(string("baz")).notTo(eq("bar"));
template <typename U>
class Eq : public UnaryMatcher<Eq<U>, U> {
 public:
  // Returns true if the given actual value is equal to this matcher's expected
  // value using the == comparison operator.
  template <typename V>
  bool match(const V& actual_value) const;

  std::string desc() const override;

 private:
  explicit Eq(const U& expected_value);

  template <typename V>
  friend Eq<V> eq(const V& expected_value);
};

// Creates a new Eq matcher with the given expected value.
template <typename V>
Eq<V> eq(const V& expected_value);

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Eq<U>::match(const V& actual_value) const {
  return actual_value == this->expected_value();
}

template <typename U>
std::string Eq<U>::desc() const {
  std::ostringstream s;
  s << "equal " << support::inspect(this->expected_value());
  return s.str();
}

// Private methods.

template<typename U>
Eq<U>::Eq(const U& expected_value) : UnaryMatcher<Eq<U>, U>(expected_value) {}

// Friend functions.

template<typename V>
Eq<V> eq(const V& expected_value) {
  return Eq<V>(expected_value);
}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_EQ_H_
