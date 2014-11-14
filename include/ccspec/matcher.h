#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include <ostream>
#include <string>

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class Matcher {
  public:
    template <typename V>
    bool match(V expected_value) const;

    virtual std::string desc() const = 0;

  protected:
    explicit Matcher(U);

    U value() const;

  private:
    const U value_;
};

template <typename ConcreteMatcher, typename U>
std::ostream& operator<<(std::ostream&, const Matcher<ConcreteMatcher, U>&);

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
