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

// Returns the string representation of a char type.
std::string inspect(char val);

// Returns the string representation of an unsigned char type.
std::string inspect(unsigned char val);

// Returns the string representation of a bool type.
std::string inspect(bool val);

// Returns the string representation of a short type.
std::string inspect(short val);

// Returns the string representation of an unsigned short type.
std::string inspect(unsigned short val);

// Returns the string representation of an int type.
std::string inspect(int val);

// Returns the string representation of an unsigned int type.
std::string inspect(unsigned int val);

// Returns the string representation of an long type.
std::string inspect(long val);

// Returns the string representation of an unsigned long type.
std::string inspect(unsigned long val);

// Returns the string representation of a long long type.
std::string inspect(long long val);

// Returns the string representation of an unsigned long long type.
std::string inspect(unsigned long long val);

// Returns the string representation of a float type.
std::string inspect(float val);

// Returns the string representation of a double type.
std::string inspect(double val);

// Returns the string representation of a long double type.
std::string inspect(long double val);

// Returns the string representation of a pointer.
std::string inspect(void* val);

// Returns the string representation of a null-terminated string.
std::string inspect(const char* s);

// Returns the string representation of a standard string.
std::string inspect(const std::string& s);

// Returns a platform-dependent string representation of an arbitrary type.
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
  char* no_output_buffer = nullptr;
  size_t* no_length = nullptr;
  int* no_status = nullptr;
  std::unique_ptr<char, void(*)(void*)> type_name(
      abi::__cxa_demangle(
          typeid(object).name(), no_output_buffer, no_length, no_status),
      std::free);
  return type_name.get();
#else
  return typeid(object).name();
#endif
}

}  // namespace support
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_SUPPORT_INSPECT_H_
