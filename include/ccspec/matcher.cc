namespace ccspec {

// Public methods.

template <typename ConcreteMatcher, typename U>
template <typename V>
bool Matcher<ConcreteMatcher, U>::match(V actual_value) const {
    return static_cast<const ConcreteMatcher*>(this)->match(actual_value);
}

// Protected methods.

template <typename ConcreteMatcher, typename U>
Matcher<ConcreteMatcher, U>::Matcher(U expected_value)
    : expected_value_(expected_value) {}

template <typename ConcreteMatcher, typename U>
Matcher<ConcreteMatcher, U>::~Matcher() {}

template <typename ConcreteMatcher, typename U>
U Matcher<ConcreteMatcher, U>::expected_value() const {
    return expected_value_;
}

// Operators.

template <typename ConcreteMatcher, typename U>
std::ostream& operator<<(std::ostream& stream,
                         const Matcher<ConcreteMatcher, U>& matcher) {
    stream << matcher.desc();
    return stream;
}

} // namespace ccspec
