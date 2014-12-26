#include <sstream>

namespace ccspec {
namespace expectation {

using ccspec::support::Exception;

// Public methods.

template <typename U, typename ConcreteMatcher, typename V>
Mismatch<U, ConcreteMatcher, V>::Mismatch(
    const U& actual_value,
    const Matcher<ConcreteMatcher, V>& matcher
) : Exception(desc(actual_value, matcher)) {}

// Private methods.

template <typename U, typename ConcreteMatcher, typename V>
std::string Mismatch<U, ConcreteMatcher, V>::desc(
    const U& actual_value,
    const Matcher<ConcreteMatcher, V>& matcher
) {
    std::ostringstream s;
    s << actual_value << ' ' << matcher;
    return s.str();
}

} // namespace expectation
} // namespace ccspec
