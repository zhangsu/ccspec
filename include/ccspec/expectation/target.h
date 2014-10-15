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
    void to(const Matcher<ConcreteMatcher, V>&) const;

  private:
    explicit Target(U);

    const U value_;

    template <typename V>
    friend Target<V> ccspec::expect(V);
};

} // namespace expectation
} // namespace ccspec

#include "target.cc"

#endif // CCSPEC_EXPECTATION_TARGET_H_
