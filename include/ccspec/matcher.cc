namespace ccspec {

// Public methods.

template <typename ConcreteMatcher, typename U>
template <typename V>
bool Matcher<ConcreteMatcher, U>::match(V expected_value) const {
    return static_cast<const ConcreteMatcher*>(this)->match(expected_value);
}

// Protected methods.

template <typename ConcreteMatcher, typename U>
Matcher<ConcreteMatcher, U>::Matcher(U value) : value_(value) {}

template <typename ConcreteMatcher, typename U>
U Matcher<ConcreteMatcher, U>::value() const {
    return value_;
}

// Operators.

template <typename ConcreteMatcher, typename U>
std::ostream& operator<<(std::ostream& stream,
                         const Matcher<ConcreteMatcher, U>& matcher) {
    stream << matcher.desc();
    return stream;
}

} // namespace ccspec
