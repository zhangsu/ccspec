#ifndef CCSPEC_MATCHERS_EQ_H_
#define CCSPEC_MATCHERS_EQ_H_

#include <string>
#include <ccspec/matcher.h>

namespace ccspec {
namespace matchers {

template <typename U>
class Eq : public Matcher<Eq<U>, U> {
  public:
    template <typename V>
    bool match(V actual_value) const;
    std::string desc() const override;

  private:
    explicit Eq(U);

    template <typename T>
    friend Eq<T> eq(T expected_value);
};

template <typename T>
Eq<T> eq(T expected_value);

} // namespace matchers
} // namespace ccspec

#include "eq.cc"

#endif // CCSPEC_MATCHERS_EQ_H_
