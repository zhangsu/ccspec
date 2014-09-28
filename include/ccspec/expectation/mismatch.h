#ifndef CCSPEC_MISMATCH_H_
#define CCSPEC_MISMATCH_H_

#include <ccspec/matcher.h>
#include "exception.h"

namespace ccspec {
namespace expectation {

template <typename ConcreteMatcher, typename U>
class Mismatch : public Exception {
  public:
    explicit Mismatch(const Matcher<ConcreteMatcher, U>&);

  private:
    const Matcher<ConcreteMatcher, U>& matcher_;
};

} // namespace expectation
} // namespace ccspec

#include "mismatch.cc"

#endif // CCSPEC_MISMATCH_H_
