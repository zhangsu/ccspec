#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include <ostream>
#include <string>

// Interface.

namespace ccspec {

template <typename ConcreteMatcher>
class Matcher {
  public:
    template <typename T>
    bool match(const T& actual_value) const;

    virtual std::string desc() const = 0;
};

template <typename ConcreteMatcher>
std::ostream& operator<<(std::ostream&, const Matcher<ConcreteMatcher>&);

}  // namespace ccspec

// Implementation.

namespace ccspec {

// Public methods.

template <typename ConcreteMatcher>
template <typename T>
bool Matcher<ConcreteMatcher>::match(const T& actual_value) const {
    return static_cast<const ConcreteMatcher*>(this)->match(actual_value);
}

// Operators.

template <typename ConcreteMatcher>
std::ostream& operator<<(std::ostream& stream,
                         const Matcher<ConcreteMatcher>& matcher) {
    stream << matcher.desc();
    return stream;
}

}  // namespace ccspec

#endif  // CCSPEC_MATCHER_H_
