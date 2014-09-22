#include <ccspec/matcher.h>
#include "exception.h"

namespace ccspec {

// Friend methods.

template <typename V>
expectation::Target<V> expect(V target) {
    return expectation::Target<V>(target);
}

namespace expectation {

// Public methods.

template <typename U>
template <typename ConcreteMatcher, typename V>
void Target<U>::to(Matcher<ConcreteMatcher, V> matcher) const {
    bool matched;
    try {
        matched = matcher.match(target_);
    } catch (...) {
        throw expectation::Exception();
    }
    if (!matched)
        throw expectation::Exception();
}

// Private methods.

template <typename U>
Target<U>::Target(U target) : target_(target) {}

} // namespace expectation
} // namespace ccspec
