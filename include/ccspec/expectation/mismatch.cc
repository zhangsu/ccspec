#include <sstream>
#include <string>
#include <ccspec/expectation/mismatch.h>

namespace ccspec {
namespace expectation {

// Public methods.

template <typename U, typename ConcreteMatcher, typename V>
Mismatch<U, ConcreteMatcher, V>::Mismatch(
    const U& value,
    const Matcher<ConcreteMatcher, V>& matcher)
    : value_(value),
      matcher_(matcher) {}

template <typename U, typename ConcreteMatcher, typename V>
std::string Mismatch<U, ConcreteMatcher, V>::toString() const {
    std::ostringstream s;
    s << value_ << ' ' << matcher_;
    return s.str();
}

} // namespace expectation
} // namespace ccspec
