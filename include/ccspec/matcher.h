#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class Matcher {
  public:
    template <typename V>
    bool match(V expected_value);

  protected:
    Matcher(U);

    U value();

  private:
    U value_;
};

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
