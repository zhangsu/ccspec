#ifndef INCLUDE_CCSPEC_EXPECTATION_MISMATCH_H_
#define INCLUDE_CCSPEC_EXPECTATION_MISMATCH_H_

#include <sstream>
#include <string>

#include "ccspec/matcher.h"
#include "ccspec/support/exception.h"
#include "ccspec/support/inspect.h"

// Interface.

namespace ccspec {
namespace expectation {

// Signifies matcher mismatch in CCSpec examples. When this exception is thrown
// by CCSpec, it means that an expectation in an example failed because the
// matcher doesn't match.
template <typename T, typename ConcreteMatcher>
class Mismatch : public ccspec::support::Exception {
 public:
  // Constructs a Mismatch exception with the given actual value and matcher
  // from which an exception description can be derived.
  Mismatch(const T& actual_value, const Matcher<ConcreteMatcher>&);

 private:
  std::string desc(const T& actual_value, const Matcher<ConcreteMatcher>&);
};

}  // namespace expectation
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace expectation {

// Public methods.

template <typename T, typename ConcreteMatcher>
Mismatch<T, ConcreteMatcher>::Mismatch(
    const T& actual_value,
    const Matcher<ConcreteMatcher>& matcher)
    : Exception(desc(actual_value, matcher)) {}

// Private methods.

template <typename T, typename ConcreteMatcher>
std::string Mismatch<T, ConcreteMatcher>::desc(
    const T& actual_value,
    const Matcher<ConcreteMatcher>& matcher) {
  std::ostringstream s;
  s << support::inspect(actual_value) << " should " << matcher;
  return s.str();
}

}  // namespace expectation
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_EXPECTATION_MISMATCH_H_
