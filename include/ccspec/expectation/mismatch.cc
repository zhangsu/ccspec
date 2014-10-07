#include <string>
#include <ccspec/expectation/mismatch.h>

namespace ccspec {
namespace expectation {

using std::string;

template <typename ConcreteMatcher, typename U>
Mismatch<ConcreteMatcher, U>::Mismatch(const Matcher<ConcreteMatcher, U>& matcher)
    : matcher_(matcher) {}

template <typename ConcreteMatcher, typename U>
string Mismatch<ConcreteMatcher, U>::toString() {
    return "stub";
}

} // namespace expectation
} // namespace ccspec
