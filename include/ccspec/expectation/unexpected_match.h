#ifndef CCSPEC_UNEXPECTED_MATCH_H_
#define CCSPEC_UNEXPECTED_MATCH_H_

#include <sstream>
#include <string>
#include <ccspec/matcher.h>
#include <ccspec/support/exception.h>
#include <ccspec/support/inspect.h>

// Interface.

namespace ccspec {
namespace expectation {

template <typename T, typename ConcreteMatcher>
class UnexpectedMatch : public ccspec::support::Exception {
  public:
    UnexpectedMatch(const T& actual_value, const Matcher<ConcreteMatcher>&);

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
UnexpectedMatch<T, ConcreteMatcher>::UnexpectedMatch(
    const T& actual_value,
    const Matcher<ConcreteMatcher>& matcher
) : Exception(desc(actual_value, matcher)) {}

// Private methods.

template <typename T, typename ConcreteMatcher>
std::string UnexpectedMatch<T, ConcreteMatcher>::desc(
    const T& actual_value,
    const Matcher<ConcreteMatcher>& matcher
) {
    std::ostringstream s;
    s << support::inspect(actual_value) << " should not " << matcher;
    return s.str();
}

}  // namespace expectation
}  // namespace ccspec

#endif  // CCSPEC_UNEXPECTED_MATCH_H_
