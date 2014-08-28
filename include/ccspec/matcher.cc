namespace ccspec {

// Protected methods.

template <typename ConcreteMatcher, typename U>
Matcher<ConcreteMatcher, U>::Matcher(U value) : value_(value) {}

template <typename ConcreteMatcher, typename U>
template <typename V>
bool Matcher<ConcreteMatcher, U>::match(V expected_value) {
    return static_cast<ConcreteMatcher*>(this)->match(expected_value);
}

template <typename ConcreteMatcher, typename U>
U Matcher<ConcreteMatcher, U>::value() {
    return value_;
}

} // namespace ccspec
