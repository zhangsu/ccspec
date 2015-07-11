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

std::string inspect(char val);
std::string inspect(unsigned char val);
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
std::string inspect(const char* s);
std::string inspect(const std::string& s);

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
