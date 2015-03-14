#ifndef CCSPEC_MATCHERS_BE_H_
#define CCSPEC_MATCHERS_BE_H_

#include <sstream>
#include <string>
#include <ccspec/unary_matcher.h>
#include <ccspec/support/inspect.h>

// Interface.

namespace ccspec {
namespace matchers {

// Matches expected value with actual value for object types by comparing their
// object identities obtained using the address-of operator &.
//
// Example:
//      struct A {};
//      A a0, a1;
//      A& a2 = a0;
//      expect(a0).to(be(a2));
//      expect(a0).notTo(be(a1));
template <typename U>
class Be : public UnaryMatcher<Be<U>, U> {
  public:
    // Returns true if the given actual value has the same object identity
    // as that of this matcher's expected value, where the identities are
    // obtained using the & address-of operator.
    template <typename V>
    bool match(const V& actual_value) const;

    // Returns the human-readable description of what this matcher matches.
    std::string desc() const override;

  private:
    explicit Be(const U& expected_value);

    // The friend class that produces various matchers that have their DSL start
    // with "be".
    friend class BeSomething;
};

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Be<U>::match(const V& actual_value) const {
    return &actual_value == &(this->expected_value());
}

template <typename U>
std::string Be<U>::desc() const {
    std::ostringstream s;
    s << "be " << support::inspect(this->expected_value());
    return s.str();
}

// Private methods.

template<typename U>
Be<U>::Be(const U& expected_value) : UnaryMatcher<Be<U>, U>(expected_value) {}

}  // namespace matchers
}  // namespace ccspec

#endif  // CCSPEC_MATCHERS_BE_H_
