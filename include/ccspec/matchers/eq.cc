#include <sstream>
#include <string>
#include <ccspec/matcher.h>

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Eq<U>::match(V expected_value) const {
    return expected_value == this->value();
}

template <typename U>
std::string Eq<U>::desc() const {
    std::ostringstream s;
    s << "should equal " << this->value();
    return s.str();
}

// Private methods.

template<typename U>
Eq<U>::Eq(U value) : Matcher<Eq<U>, U>(value) {}

// Friend functions.

template<typename U>
Eq<U> eq(U value) {
    return Eq<U>(value);
}

} // namespace matchers
} // namespace ccspec
