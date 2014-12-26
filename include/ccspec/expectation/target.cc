#include "mismatch.h"

namespace ccspec {

// Friend functions.

template <typename V>
expectation::Target<V> expect(V actual_value) {
    return expectation::Target<V>(actual_value);
}

namespace expectation {

// Public methods.

template <typename U>
template <typename ConcreteMatcher, typename V>
void Target<U>::to(const Matcher<ConcreteMatcher, V>& matcher) const {
    if (!matcher.match(actual_value_))
        throw Mismatch<U, ConcreteMatcher, V>(actual_value_, matcher);
}

// Private methods.

template <typename U>
Target<U>::Target(U actual_value) : actual_value_(actual_value) {}

} // namespace expectation
} // namespace ccspec
