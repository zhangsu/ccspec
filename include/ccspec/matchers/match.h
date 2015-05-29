#ifndef INCLUDE_CCSPEC_MATCHERS_MATCH_H_
#define INCLUDE_CCSPEC_MATCHERS_MATCH_H_

#include <sstream>
#include <string>

#include "ccspec/support/inspect.h"
#include "ccspec/unary_matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches if the actual value's match method returns true when the method is
// given this matcher's expected value.
//
// Example:
//      // The actual value is eq(3) and this matcher's expected value is 3,
//      // this matches because eq(3).match(3) returns true.
//      expect(eq(3)).to(match(3));
//
//      // The actual value is (be < 0) and this matcher's expected value is 1,
//      // this does not match because (be < 0).match(1) returns false.
//      expect(be < 0).notTo(match(1));
template <typename U>
class Match : public UnaryMatcher<Match<U>, U> {
 public:
  // Returns true if the match method of the actual value returns true when the
  // method is given this matcher's expected value.
  template <typename V>
  bool match(const V& actual_value) const;

  std::string desc() const override;

 private:
  explicit Match(const U& expected_value);

  template <typename V>
  friend Match<V> match(const V& expected_value);
};

// Creates a new Match matcher with the given expected value.
template <typename V>
Match<V> match(const V& expected_value);

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Match<U>::match(const V& actual_value) const {
  return actual_value.match(this->expected_value());
}

template <typename U>
std::string Match<U>::desc() const {
  std::ostringstream s;
  s << "match " << support::inspect(this->expected_value());
  return s.str();
}

// Private methods.

template<typename U>
Match<U>::Match(const U& expected_value)
  : UnaryMatcher<Match<U>, U>(expected_value) {}

// Friend functions.

template<typename V>
Match<V> match(const V& expected_value) {
  return Match<V>(expected_value);
}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_MATCH_H_
