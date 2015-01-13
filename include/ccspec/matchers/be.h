#ifndef CCSPEC_MATCHERS_BE_H_
#define CCSPEC_MATCHERS_BE_H_

#include <sstream>
#include <string>
#include <ccspec/matcher.h>
#include <ccspec/support/inspect.h>

// Interface.

namespace ccspec {
namespace matchers {

template <typename U>
class Be : public Matcher<Be<U>, U> {
  public:
    template <typename V>
    bool match(const V& actual_value) const;
    std::string desc() const override;

  private:
    explicit Be(const U& expected_value);

    const U& expected_value_ref_;

    friend class BeSomething;
};

} // namespace matchers
} // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Be<U>::match(const V& actual_value) const {
    return &actual_value == &expected_value_ref_;
}

template <typename U>
std::string Be<U>::desc() const {
    std::ostringstream s;
    s << "should be " << support::inspect(expected_value_ref_);
    return s.str();
}

// Private methods.

template<typename U>
Be<U>::Be(const U& expected_value) : expected_value_ref_(expected_value) {}

} // namespace matchers
} // namespace ccspec

#endif // CCSPEC_MATCHERS_BE_H_
