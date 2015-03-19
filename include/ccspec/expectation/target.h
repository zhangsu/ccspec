#ifndef CCSPEC_EXPECTATION_TARGET_H_
#define CCSPEC_EXPECTATION_TARGET_H_

#include "ccspec/matcher.h"
#include "ccspec/matchers/be.h"
#include "ccspec/expectation/mismatch.h"
#include "ccspec/expectation/unexpected_match.h"

// Interface.

namespace ccspec {
namespace expectation {

template <typename U>
class Target;

}  // namespace expectation

template <typename T>
expectation::Target<T> expect(const T& actual_value);

namespace expectation {

template <typename U>
class Target {
  public:
    template <typename ConcreteMatcher>
    void to(const Matcher<ConcreteMatcher>&) const;
    template <typename ConcreteMatcher>
    void notTo(const Matcher<ConcreteMatcher>&) const;

  private:
    explicit Target(const U& actual_value);

    const U& actual_value_;

    template <typename V>
    friend Target<V> ccspec::expect(const V& actual_value);
};

}  // namespace expectation
}  // namespace ccspec

// Implementation.

namespace ccspec {

// Friend functions.

template <typename V>
expectation::Target<V> expect(const V& actual_value) {
    return expectation::Target<V>(actual_value);
}

namespace expectation {

// Public methods.

template <typename U>
template <typename ConcreteMatcher>
void Target<U>::to(const Matcher<ConcreteMatcher>& matcher) const {
    if (!matcher.match(actual_value_))
        throw Mismatch<U, ConcreteMatcher>(actual_value_, matcher);
}

template <typename U>
template <typename ConcreteMatcher>
void Target<U>::notTo(const Matcher<ConcreteMatcher>& matcher) const {
    if (matcher.match(actual_value_))
        throw UnexpectedMatch<U, ConcreteMatcher>(actual_value_, matcher);
}

// Private methods.

template <typename U>
Target<U>::Target(const U& actual_value) : actual_value_(actual_value) {}

}  // namespace expectation
}  // namespace ccspec

#endif  // CCSPEC_EXPECTATION_TARGET_H_
