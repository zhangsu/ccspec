#ifndef CCSPEC_EXPECTATION_TARGET_H_
#define CCSPEC_EXPECTATION_TARGET_H_

#include "matcher.h"

namespace ccspec {

template <typename U>
class ExpectationTarget {
  public:
    template <typename ConcreteMatcher, typename V>
    void to(Matcher<ConcreteMatcher, V>);

  private:
    ExpectationTarget(U);

    U target_;

    template <typename V>
    friend ExpectationTarget<V> expect(V);
};

} // namespace ccspec

#include "expectation_target.cc"

#endif // CCSPEC_EXPECTATION_TARGET_H_
