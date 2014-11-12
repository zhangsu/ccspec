#ifndef CCSPEC_EXPECTATION_EXCEPTION_H_
#define CCSPEC_EXPECTATION_EXCEPTION_H_

#include <exception>
#include <string>

namespace ccspec {
namespace expectation {

class Exception : public std::exception {
  public:
    virtual const char* what() const noexcept;
    virtual const std::string& desc() const;

  protected:
    explicit Exception(std::string desc);

  private:
    const std::string desc_;
};

} // namespace expectation
} // namespace ccspec

#endif // CCSPEC_EXPECTATION_EXCEPTION_H_
