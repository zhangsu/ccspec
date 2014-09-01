#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include <ccspec/expectation/expectation_target.h>

namespace ccspec {
namespace expectation {

template <typename U>
class ExpectationTarget;

} // namespace expectation

template <typename ConcreteMatcher, typename U>
class Matcher {
  protected:
    Matcher(U);

    template <typename V>
    bool match(V expected_value);
    U value();

  private:
    U value_;

    template <typename V>
    friend class expectation::ExpectationTarget;
};

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
