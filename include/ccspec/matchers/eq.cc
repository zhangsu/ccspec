#include <ccspec/matcher.h>
#include <iostream>
using namespace std;

namespace ccspec {

// Public methods.

template <typename U>
template <typename V>
void Eq<U>::match(V expected_value) {
    if (expected_value != this->value())
        throw 1;
}

// Private methods.

template<typename U>
Eq<U>::Eq(U value) : Matcher<Eq<U>, U>(value) {}

// Friend methods.

template<typename U>
Eq<U> eq(U value) {
    return Eq<U>(value);
}

} // namespace ccspec
