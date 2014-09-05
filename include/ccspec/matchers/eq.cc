#include <ccspec/matcher.h>

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Eq<U>::match(V expected_value) const {
    return expected_value == this->value();
}

// Private methods.

template<typename U>
Eq<U>::Eq(U value) : Matcher<Eq<U>, U>(value) {}

// Friend methods.

template<typename U>
Eq<U> eq(U value) {
    return Eq<U>(value);
}

} // namespace matchers
} // namespace ccspec
