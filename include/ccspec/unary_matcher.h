#ifndef CCSPEC_UNARY_MATCHER_H_
#define CCSPEC_UNARY_MATCHER_H_

#include <ccspec/matcher.h>

// Interface.

namespace ccspec {

template <typename ConcreteMatcher, typename T>
class UnaryMatcher : public Matcher<ConcreteMatcher> {
  protected:
    explicit UnaryMatcher(const T& expected_value);
    virtual ~UnaryMatcher();

    const T& expected_value() const;

  private:
    const T& expected_value_;
};

} // namespace ccspec

// Implementation.

namespace ccspec {

// Protected methods.

template <typename ConcreteMatcher, typename T>
UnaryMatcher<ConcreteMatcher, T>::UnaryMatcher(const T& expected_value)
    : expected_value_(expected_value) {}

template <typename ConcreteMatcher, typename T>
UnaryMatcher<ConcreteMatcher, T>::~UnaryMatcher() {}

template <typename ConcreteMatcher, typename T>
const T& UnaryMatcher<ConcreteMatcher, T>::expected_value() const {
    return expected_value_;
}

} // namespace ccspec

#endif // CCSPEC_UNARY_MATCHER_H_
