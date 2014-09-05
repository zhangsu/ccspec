#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class Matcher {
  public:
    template <typename V>
    bool match(V expected_value) const;

  protected:
    Matcher(U);

    U value() const;

  private:
    const U value_;
};

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
