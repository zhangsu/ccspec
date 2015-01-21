#ifndef CCSPEC_UNARY_MATCHER_H_
#define CCSPEC_UNARY_MATCHER_H_

#include <ccspec/matcher.h>

// Interface.

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class UnaryMatcher : public Matcher<ConcreteMatcher> {
  protected:
    explicit UnaryMatcher(U expected_value);
    virtual ~UnaryMatcher();

    U expected_value() const;

  private:
    const U expected_value_;
};

} // namespace ccspec

// Implementation.

namespace ccspec {

// Protected methods.

template <typename ConcreteMatcher, typename U>
UnaryMatcher<ConcreteMatcher, U>::UnaryMatcher(U expected_value)
    : expected_value_(expected_value) {}

template <typename ConcreteMatcher, typename U>
UnaryMatcher<ConcreteMatcher, U>::~UnaryMatcher() {}

template <typename ConcreteMatcher, typename U>
U UnaryMatcher<ConcreteMatcher, U>::expected_value() const {
    return expected_value_;
}

} // namespace ccspec

#endif // CCSPEC_UNARY_MATCHER_H_
