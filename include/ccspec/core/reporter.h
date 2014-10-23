#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include <exception>
#include "example.h"

namespace ccspec {
namespace core {

class Reporter {
public:
    void examplePassed(const Example& example) const;
    void exampleFailed(const Example& example, const std::exception&) const;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
