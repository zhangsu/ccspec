#ifndef CCSPEC_MATCHER_H_
#define CCSPEC_MATCHER_H_

#include <string>

namespace ccspec {

template <typename ConcreteMatcher, typename U>
class Matcher {
  public:
    template <typename V>
    bool match(V expected_value) const;

    virtual std::string toString() const = 0;

  protected:
    explicit Matcher(U);

    U value() const;

  private:
    const U value_;
};

} // namespace ccspec

#include "matcher.cc"

#endif // CCSPEC_MATCHER_H_
