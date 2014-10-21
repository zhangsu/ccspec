#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include "example.h"

namespace ccspec {
namespace core {

class Reporter {
public:
    void examplePassed(const Example& example) const;
    void exampleFailed(const Example& example) const;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
