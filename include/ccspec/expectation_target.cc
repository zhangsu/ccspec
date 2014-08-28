#include "matcher.h"

namespace ccspec {

// Public methods.

template <typename U>
template <typename ConcreteMatcher, typename V>
void ExpectationTarget<U>::to(Matcher<ConcreteMatcher, V> matcher) {
    if (!matcher.match(target_))
        throw "CCSpecException";
}

// Private methods.

template <typename U>
ExpectationTarget<U>::ExpectationTarget(U target) : target_(target) {}

// Friend methods.

template <typename V>
ExpectationTarget<V> expect(V target) {
    return ExpectationTarget<V>(target);
}

} // namespace ccspec
