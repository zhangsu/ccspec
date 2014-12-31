#ifndef CCSPEC_EXPECTATION_TARGET_H_
#define CCSPEC_EXPECTATION_TARGET_H_

#include <ccspec/matcher.h>
#include "mismatch.h"

// Interface.

namespace ccspec {
namespace expectation {

template <typename U>
class Target;

} // namespace expectation

template <typename T>
expectation::Target<T> expect(T actual_value);

namespace expectation {

template <typename U>
class Target {
  public:
    template <typename ConcreteMatcher, typename V>
    void to(const Matcher<ConcreteMatcher, V>&) const;

  private:
    explicit Target(U actual_value);

    const U actual_value_;

    template <typename V>
    friend Target<V> ccspec::expect(V actual_value);
};

} // namespace expectation
} // namespace ccspec

// Implementation.

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

#endif // CCSPEC_EXPECTATION_TARGET_H_
