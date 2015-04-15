#ifndef INCLUDE_CCSPEC_MATCHERS_BE_TRUTHY_H_
#define INCLUDE_CCSPEC_MATCHERS_BE_TRUTHY_H_

#include <string>

#include "ccspec/matcher.h"

// Interface.

namespace ccspec {
namespace matchers {

// Matches if the actual value evalutes to true after applying the Boolean
// negation operator ! twice.
//
// Example:
//      expect(2 > 1).to(be_truthy);
//      expect(-2 <= -1).to(be_truthy);
class BeTruthy : public Matcher<BeTruthy> {
 public:
  // Returns the singleton of BeTruthy.
  static const BeTruthy& instance();

  // Returns true if the given actual value is true after applying the logical
  // negation operator ! twice.
  template <typename T>
  bool match(const T& actual_value) const;

  std::string desc() const override;

 private:
  BeTruthy() = default;
  // Deletes copy constructor and assignment operator to maintain singleton
  // property.
  BeTruthy(const BeTruthy&) = delete;
  void operator =(const BeTruthy&) = delete;
};

// Points to the BeTruthy singleton.
extern const BeTruthy& be_truthy;

}  // namespace matchers
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace matchers {

// Public methods.

template <typename T>
bool BeTruthy::match(const T& actual_value) const {
  return !!actual_value;
}

}  // namespace matchers
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_MATCHERS_BE_TRUTHY_H_
