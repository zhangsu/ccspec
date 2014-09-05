#include <ccspec/matcher.h>

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
    if (!matcher.match(target_))
        throw "CCSpecException";
}

// Private methods.

template <typename U>
Target<U>::Target(U target) : target_(target) {}

} // namespace expectation
} // namespace ccspec
