#ifndef INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_
#define INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_

#include <exception>
#include <string>

namespace ccspec {
namespace support {

// Base class for CCSpec exceptions.
class Exception : public std::exception {
 public:
  const char* what() const noexcept override;

 protected:
  // Constructs a CCSpec exception with the given description.
  explicit Exception(std::string desc);

 private:
  const std::string desc_;
};

}  // namespace support
}  // namespace ccspec

#endif  // INCLUDE_CCSPEC_SUPPORT_EXCEPTION_H_
