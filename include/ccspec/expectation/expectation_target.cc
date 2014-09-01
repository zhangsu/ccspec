#include <ccspec/matcher.h>

namespace ccspec {

// Friend methods.

template <typename V>
expectation::ExpectationTarget<V> expect(V target) {
    return expectation::ExpectationTarget<V>(target);
}

namespace expectation {

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

} // namespace expectation
} // namespace ccspec
