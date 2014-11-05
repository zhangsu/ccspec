#include <exception>
#include <ccspec/matcher.h>
#include "unexpected_throw.h"
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
    bool matched;
    try {
        matched = matcher.match(value_);
    } catch (const std::exception& e) {
        throw expectation::UnexpectedThrow(e);
    }
    if (!matched)
        throw expectation::Mismatch<U, ConcreteMatcher, V>(value_, matcher);
}

// Private methods.

template <typename U>
Target<U>::Target(U value) : value_(value) {}

} // namespace expectation
} // namespace ccspec
