#ifndef INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_
#define INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_

#include <functional>
#include <sstream>
#include <string>

#include "ccspec/support/inspect.h"
#include "ccspec/unary_matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

template <typename U>
class BeComparedTo : public UnaryMatcher<BeComparedTo<U>, U> {
  public:
    template <typename V>
    bool match(const V& actual_value) const;
    std::string desc() const override;

  private:
    typedef std::function<bool (U, U)> Comparator;

    explicit BeComparedTo(Comparator compare, std::string comparator_name,
                          const U& expected_value);

    Comparator compare_;
    std::string comparator_name_;

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
bool BeComparedTo<U>::match(const V& actual_value) const {
    return compare_(actual_value, this->expected_value());
}

template <typename U>
std::string BeComparedTo<U>::desc() const {
    std::ostringstream s;
    s << "be " << comparator_name_ << ' '
      << support::inspect(this->expected_value());
    return s.str();
}

// Private methods.

template<typename U>
BeComparedTo<U>::BeComparedTo(Comparator compare, std::string comparator_name,
                              const U& expected_value)
    : UnaryMatcher<BeComparedTo<U>, U>(expected_value),
      compare_(compare),
      comparator_name_(comparator_name) {}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_BE_COMPARED_TO_H_
