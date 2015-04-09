#ifndef INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_
#define INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_

#include <functional>
#include <sstream>
#include <string>

#include "ccspec/support/inspect.h"
#include "ccspec/unary_matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches expected value with actual value by comparing them with a caller-
// specified binary predicate, where the first argument of the predicate is
// passed the actual value and the second argument is passed the expected value.
//
// This matcher can only be instantiated by the singleton `be` of the friend
// class BeSomething.
//
// Example:
//      expect(3).to(be < 4);
//      expect(3.5).to(be >= 3.4999);
//      expect(string("foo")).notTo(be == string("bar"));
template <typename U>
class BeComparedTo : public UnaryMatcher<BeComparedTo<U>, U> {
 public:
  // Returns true if this matcher's binary predicate returns true with the first
  // argument being the given actual value and the second argument being this
  // matcher's expected value.
  template <typename V>
  bool match(const V& actual_value) const;

  std::string desc() const override;

 private:
  typedef std::function<bool (U, U)> Comparator;

  explicit BeComparedTo(Comparator compare, std::string comparator_name,
                        const U& expected_value);

  // Compares two arguments and returns true or false.
  Comparator compare_;

  // Stores the human-readable name of the comparator used for display.
  std::string comparator_name_;

  // Produces various matchers that have their DSL start with "be".
  friend class BeSomething;
};

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool BeComparedTo<U>::match(const V& actual_value) const {
  return compare_(actual_value, this->expected_value());
}

template <typename U>
std::string BeComparedTo<U>::desc() const {
  std::ostringstream s;
  s << "be " << comparator_name_ << ' '
    << support::inspect(this->expected_value());
  return s.str();
}

// Private methods.

template<typename U>
BeComparedTo<U>::BeComparedTo(
    Comparator compare,
    std::string comparator_name,
    const U& expected_value)
    : UnaryMatcher<BeComparedTo<U>, U>(expected_value),
      compare_(compare),
      comparator_name_(comparator_name) {}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_
