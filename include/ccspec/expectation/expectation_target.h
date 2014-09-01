#ifndef CCSPEC_EXPECTATION_TARGET_H_
#define CCSPEC_EXPECTATION_TARGET_H_

#include <ccspec/matcher.h>

namespace ccspec {
namespace expectation {

template <typename U>
class ExpectationTarget;

} // namespace expectation

template <typename T>
expectation::ExpectationTarget<T> expect(T);

namespace expectation {

template <typename U>
class ExpectationTarget {
  public:
    template <typename ConcreteMatcher, typename V>
    void to(Matcher<ConcreteMatcher, V>);

  private:
    ExpectationTarget(U);

    U target_;

    template <typename V>
    friend ExpectationTarget<V> ccspec::expect(V);
};

} // namespace expectation
} // namespace ccspec

#include "expectation_target.cc"

#endif // CCSPEC_EXPECTATION_TARGET_H_
