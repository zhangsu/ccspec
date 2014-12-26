#include <sstream>
#include <string>
#include <ccspec/matcher.h>

namespace ccspec {
namespace matchers {

// Public methods.

template <typename U>
template <typename V>
bool Eq<U>::match(V actual_value) const {
    return actual_value == this->expected_value();
}

template <typename U>
std::string Eq<U>::desc() const {
    std::ostringstream s;
    s << "should equal " << this->expected_value();
    return s.str();
}

// Private methods.

template<typename U>
Eq<U>::Eq(U expected_value) : Matcher<Eq<U>, U>(expected_value) {}

// Friend functions.

template<typename U>
Eq<U> eq(U expected_value) {
    return Eq<U>(expected_value);
}

} // namespace matchers
} // namespace ccspec
