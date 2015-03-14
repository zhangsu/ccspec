#ifndef CCSPEC_MATCHERS_BE_FALSEY_H_
#define CCSPEC_MATCHERS_BE_FALSEY_H_

#include <string>
#include <ccspec/matcher.h>

// Interface.

namespace ccspec {
namespace matchers {

class BeFalsey : public Matcher<BeFalsey> {
  public:
    static const BeFalsey& instance();

    template <typename T>
    bool match(const T& actual_value) const;
    std::string desc() const override;

  private:
    BeFalsey();
    BeFalsey(const BeFalsey&) = delete;
    void operator =(const BeFalsey&) = delete;
};

extern const BeFalsey& be_falsey;

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename T>
bool BeFalsey::match(const T& actual_value) const {
    return !actual_value;
}

}  // namespace matchers
}  // namespace ccspec

#endif  // CCSPEC_MATCHERS_BE_FALSEY_H_
