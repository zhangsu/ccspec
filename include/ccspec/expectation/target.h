#ifndef CCSPEC_EXPECTATION_TARGET_H_
#define CCSPEC_EXPECTATION_TARGET_H_

#include <ccspec/matcher.h>

namespace ccspec {
namespace expectation {

template <typename U>
class Target;

} // namespace expectation

template <typename T>
expectation::Target<T> expect(T);

namespace expectation {

template <typename U>
class Target {
  public:
    template <typename ConcreteMatcher, typename V>
    void to(Matcher<ConcreteMatcher, V>);

  private:
    Target(U);

    U target_;

    template <typename V>
    friend Target<V> ccspec::expect(V);
};

} // namespace expectation
} // namespace ccspec

#include "target.cc"

#endif // CCSPEC_EXPECTATION_TARGET_H_
