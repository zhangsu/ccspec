#ifndef CCSPEC_SUPPORT_EXCEPTION_H_
#define CCSPEC_SUPPORT_EXCEPTION_H_

#include <exception>
#include <string>

namespace ccspec {
namespace support {

class Exception : public std::exception {
  public:
    virtual const char* what() const noexcept;
    virtual const std::string& desc() const;

  protected:
    explicit Exception(std::string desc);

  private:
    const std::string desc_;
};

} // namespace support
} // namespace ccspec

#endif // CCSPEC_SUPPORT_EXCEPTION_H_
