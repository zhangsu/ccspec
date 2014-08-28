#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include "expectation_target.h"

namespace ccspec {

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
    friend class ExpectationTarget;
};

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
