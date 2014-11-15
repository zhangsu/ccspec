#ifndef CCSPEC_MISMATCH_H_
#define CCSPEC_MISMATCH_H_

#include <string>
#include <ccspec/matcher.h>
#include <ccspec/support/exception.h>

namespace ccspec {
namespace expectation {

template <typename U, typename ConcreteMatcher, typename V>
class Mismatch : public ccspec::support::Exception {
  public:
    Mismatch(const U& value, const Matcher<ConcreteMatcher, V>&);

  private:
    std::string desc(const U& value, const Matcher<ConcreteMatcher, V>&);
};

} // namespace expectation
} // namespace ccspec

#include "mismatch.cc"

#endif // CCSPEC_MISMATCH_H_
