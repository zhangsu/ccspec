#ifndef CCSPEC_SUPPORT_INSPECT_H_
#define CCSPEC_SUPPORT_INSPECT_H_

#include <cstdlib>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <typeinfo>
#include <iostream>

// Interface.

namespace ccspec {
namespace support {

std::string inspect(bool val);
std::string inspect(short val);
std::string inspect(unsigned short val);
std::string inspect(int val);
std::string inspect(unsigned int val);
std::string inspect(long val);
std::string inspect(unsigned long val);
std::string inspect(long long val);
std::string inspect(unsigned long long val);
std::string inspect(float val);
std::string inspect(double val);
std::string inspect(long double val);
std::string inspect(void* val);
std::string inspect(std::streambuf* sb);
std::string inspect(std::ostream& (*pf)(std::ostream&));
std::string inspect(std::ios& (*pf)(std::ios&));
std::string inspect(std::ios_base& (*pf)(std::ios_base&));

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
