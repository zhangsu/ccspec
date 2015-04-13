#ifndef INCLUDE_CCSPEC_MATCHERS_BE_FALSEY_H_
#define INCLUDE_CCSPEC_MATCHERS_BE_FALSEY_H_

#include <string>

#include "ccspec/matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches if the actual value evalutes to false after applying the Boolean
// negation operator !.
//
// Example:
//      expect(2 < 1).to(be_falsey);
//      expect(-2 >= -1).to(be_falsey);
class BeFalsey : public Matcher<BeFalsey> {
 public:
  // Returns the singleton of BeFalsey.
  static const BeFalsey& instance();

  // Returns true if the given actual value is false after applying the logical
  // negation operator !.
  template <typename T>
  bool match(const T& actual_value) const;

  std::string desc() const override;

 private:
  BeFalsey() = default;
  // Deletes copy constructor and assignment operator to maintain singleton
  // property.
  BeFalsey(const BeFalsey&) = delete;
  void operator =(const BeFalsey&) = delete;
};

// Points to the BeFalsey singleton.
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

#endif  // INCLUDE_CCSPEC_MATCHERS_BE_FALSEY_H_
