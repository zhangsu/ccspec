#ifndef INCLUDE_CCSPEC_SUPPORT_INSPECT_H_
#define INCLUDE_CCSPEC_SUPPORT_INSPECT_H_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>

#ifndef _MSC_VER
#include <cxxabi.h>
#endif  // _MSC_VER

// Interface.

namespace ccspec {
namespace support {

std::string inspect(char);
std::string inspect(unsigned char);
std::string inspect(bool);
std::string inspect(short);
std::string inspect(unsigned short);
std::string inspect(int);
std::string inspect(unsigned int);
std::string inspect(long);
std::string inspect(unsigned long);
std::string inspect(long long);
std::string inspect(unsigned long long);
std::string inspect(float);
std::string inspect(double);
std::string inspect(long double);
std::string inspect(void*);
std::string inspect(const char*);
std::string inspect(const std::string&);
std::string inspect(std::streambuf*);
std::string inspect(std::ostream& (*pf)(std::ostream&));
std::string inspect(std::ios& (*pf)(std::ios&));
std::string inspect(std::ios_base& (*pf)(std::ios_base&));

template <typename T>
std::string inspect(const T&);

}  // namespace support
}  // namespace ccspec

// Implementation.

namespace ccspec {
namespace support {

template <typename T>
std::string inspect(const T& object) {
#ifndef _MSC_VER
    std::unique_ptr<char, void(*)(void*)> type_name(
        abi::__cxa_demangle(typeid(object).name(), nullptr, nullptr, nullptr),
        std::free);
    return type_name.get();
#else
    return typeid(object).name();
#endif
}

}  // namespace support
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_SUPPORT_INSPECT_H_
