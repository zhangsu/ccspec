#ifndef INCLUDE_CCSPEC_MATCHERS_CONTAIN_H_
#define INCLUDE_CCSPEC_MATCHERS_CONTAIN_H_

#include <sstream>
#include <string>

#include "ccspec/support/inspect.h"
#include "ccspec/unary_matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches if the actual string contains the expected substring.
//
// Example:
//      expect(string("test")).to(contain("t"));
//      expect("baz").notTo(contain(string("bar")));
template <typename U>
class Contain : public UnaryMatcher<Contain<U>, U> {
 public:
  // Returns true if this matcher's expected string is a substring of the given
  // actual string.
  template <typename V>
  bool match(const V& actual_value) const;

  std::string desc() const override;

 private:
  explicit Contain(const U& expected_value);

  template <typename V>
  friend Contain<V> contain(const V& expected_value);
};

// Creates a new Contain matcher with the given expected value.
template <typename V>
Contain<V> contain(const V& expected_value);

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Contain<U>::match(const V& actual_value) const {
  return std::string(actual_value).find(std::string(this->expected_value()))
      != std::string::npos;
}

template <typename U>
std::string Contain<U>::desc() const {
  std::ostringstream s;
  s << "contain " << this->expected_value();
  return s.str();
}

// Private methods.

template<typename U>
Contain<U>::Contain(const U& expected_value)
    : UnaryMatcher<Contain<U>, U>(expected_value) {}

// Friend functions.

template<typename V>
Contain<V> contain(const V& expected_value) {
  return Contain<V>(expected_value);
}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_CONTAIN_H_
