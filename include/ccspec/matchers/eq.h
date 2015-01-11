#ifndef CCSPEC_MATCHERS_EQ_H_
#define CCSPEC_MATCHERS_EQ_H_

#include <sstream>
#include <string>
#include <ccspec/unary_matcher.h>
#include <ccspec/support/inspect.h>

// Interface.

namespace ccspec {
namespace matchers {

template <typename U>
class Eq : public UnaryMatcher<Eq<U>, U> {
  public:
    template <typename V>
    bool match(V actual_value) const;
    std::string desc() const override;

  private:
    explicit Eq(U expected_value);

    template <typename T>
    friend Eq<T> eq(T expected_value);
};

template <typename T>
Eq<T> eq(T expected_value);

} // namespace matchers
} // namespace ccspec

// Implementation.

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
    s << "should equal " << support::inspect(this->expected_value());
    return s.str();
}

// Private methods.

template<typename U>
Eq<U>::Eq(U expected_value) : UnaryMatcher<Eq<U>, U>(expected_value) {}

// Friend functions.

template<typename U>
Eq<U> eq(U expected_value) {
    return Eq<U>(expected_value);
}

} // namespace matchers
} // namespace ccspec

#endif // CCSPEC_MATCHERS_EQ_H_
