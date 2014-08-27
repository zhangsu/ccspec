#ifndef CCSPEC_MATCHERS_EQ_H_
#define CCSPEC_MATCHERS_EQ_H_

#include <matcher.h>

namespace ccspec {

template <typename U>
class Eq : public Matcher<Eq<U>, U> {
  public:
    template <typename V>
    void match(V expected_value);

  private:
    Eq(U);

    template <typename T>
    friend Eq<T> eq(T);
};

} // namespace ccspec

#include "eq.cc"

#endif // CCSPEC_MATCHERS_EQ_H_
