#include <ccspec/matcher.h>
#include "mismatch.h"

namespace ccspec {

// Friend functions.

template <typename V>
expectation::Target<V> expect(V value) {
    return expectation::Target<V>(value);
}

namespace expectation {

// Public methods.

template <typename U>
template <typename ConcreteMatcher, typename V>
void Target<U>::to(const Matcher<ConcreteMatcher, V>& matcher) const {
    if (!matcher.match(value_))
        throw expectation::Mismatch<U, ConcreteMatcher, V>(value_, matcher);
}

// Private methods.

template <typename U>
Target<U>::Target(U value) : value_(value) {}

} // namespace expectation
} // namespace ccspec
