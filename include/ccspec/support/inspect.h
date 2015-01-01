#ifndef CCSPEC_SUPPORT_INSPECT_H_
#define CCSPEC_SUPPORT_INSPECT_H_

#include <cstdlib>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <string>
#include <typeinfo>
#include <ccspec/support/inspect.h>

// Interface.

namespace ccspec {
namespace support {

template <typename T>
std::string inspect(const T&);

} // namespace support
} // namespace ccspec

// Implementation.

namespace ccspec {
namespace support {

template <typename T>
std::string inspect(const T& object) {
#ifndef _MSC_VER
    std::unique_ptr<char, void(*)(void*)> type_name(
        abi::__cxa_demangle(typeid(object).name(), nullptr, nullptr, nullptr),
        std::free
    );
    return type_name.get();
#else
    return typeid(object).name();
#endif
}

} // namespace support
} // namespace ccspec

#endif // CCSPEC_SUPPORT_INSPECT_H_
