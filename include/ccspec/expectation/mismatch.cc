#include <sstream>
#include <string>
#include <ccspec/expectation/mismatch.h>

namespace ccspec {
namespace expectation {

// Public methods.

template <typename U, typename ConcreteMatcher, typename V>
Mismatch<U, ConcreteMatcher, V>::Mismatch(
    const U& value,
    const Matcher<ConcreteMatcher, V>& matcher
) : Exception(desc(value, matcher)) {}

// Private methods.

template <typename U, typename ConcreteMatcher, typename V>
std::string Mismatch<U, ConcreteMatcher, V>::desc(
    const U& value,
    const Matcher<ConcreteMatcher, V>& matcher
) {
    std::ostringstream s;
    s << value << ' ' << matcher;
    return s.str();
}

} // namespace expectation
} // namespace ccspec
