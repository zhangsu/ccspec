namespace ccspec {

// Protected methods.

template <typename ConcreteMatcher, typename U>
Matcher<ConcreteMatcher, U>::Matcher(U value) : value_(value) {}

template <typename ConcreteMatcher, typename U>
template <typename V>
void Matcher<ConcreteMatcher, U>::match(V expected_value) {
    static_cast<ConcreteMatcher*>(this)->match(expected_value);
}

template <typename ConcreteMatcher, typename U>
U Matcher<ConcreteMatcher, U>::value() {
    return value_;
}

} // namespace ccspec
