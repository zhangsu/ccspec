#include <ccspec/expectation/mismatch.h>

namespace ccspec {
namespace expectation {

template <typename ConcreteMatcher, typename U>
Mismatch<ConcreteMatcher, U>::Mismatch(const Matcher<ConcreteMatcher, U>& matcher)
    : matcher_(matcher) {}

} // namespace expectation
} // namespace ccspec
