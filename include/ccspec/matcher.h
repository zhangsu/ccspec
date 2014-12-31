#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include <ostream>
#include <string>

// Interface.

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class Matcher {
  public:
    template <typename V>
    bool match(V actual_value) const;

    virtual std::string desc() const = 0;

  protected:
    explicit Matcher(U expected_value);
    virtual ~Matcher();

    U expected_value() const;

  private:
    const U expected_value_;
};

template <typename ConcreteMatcher, typename U>
std::ostream& operator<<(std::ostream&, const Matcher<ConcreteMatcher, U>&);

} // namespace ccspec

// Implementation.

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

#endif // CCSPEC_MATCHER_H_
