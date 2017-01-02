#include <cstring>
#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

namespace spec {
namespace support {

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::contain;
using ccspec::matchers::eq;
using ccspec::support::inspect;

auto inspect_spec = describe("::inspect", [] {
  it("returns the string value for char", [] {
    char c = 'x';
    expect(inspect(c)).to(eq("x"));
  });

  it("returns the string value for unsigned char", [] {
    unsigned char c = 'x';
    expect(inspect(c)).to(eq("x"));
  });

  it("returns the string value for bool", [] {
    bool b = true;
    expect(inspect(b)).to(eq("true"));
  });

  it("returns the value for short", [] {
    short s = 32767;
    expect(inspect(s)).to(eq("32767"));
  });

  it("returns the value for unsigned short", [] {
    unsigned short s = 65535;
    expect(inspect(s)).to(eq("65535"));
  });

  it("returns the value for int", [] {
    int i = 1234567;
    expect(inspect(i)).to(eq("1234567"));
  });

  it("returns the value for unsigned int", [] {
    unsigned int i = 1234567324;
    expect(inspect(i)).to(eq("1234567324"));
  });

  it("returns the value for long", [] {
    long l = 12345678;
    expect(inspect(l)).to(eq("12345678"));
  });

  it("returns the value for unsigned long", [] {
    unsigned long l = 12345673243;
    expect(inspect(l)).to(eq("12345673243"));
  });

  it("returns the value for long long", [] {
    long long l = 1234567890987654321;
    expect(inspect(l)).to(eq("1234567890987654321"));
  });

  it("returns the value for unsigned long long", [] {
    unsigned long long l = 5234567890987654321;
    expect(inspect(l)).to(eq("5234567890987654321"));
  });

  it("returns the value for unsigned long long", [] {
    unsigned long long l = 5234567890987654321;
    expect(inspect(l)).to(eq("5234567890987654321"));
  });

  it("returns the value for float", [] {
    float f = 3.14;
    expect(inspect(f)).to(eq("3.14"));
  });

  it("returns the value for double", [] {
    double f = 3.14159268373523;
    expect(inspect(f)).to(eq("3.14159268373523"));
  });

  it("returns the numerical value for void*", [] {
    void* p = reinterpret_cast<void*>(0xffffffff);
    expect(inspect(p)).to(eq("0xffffffff"));
  });

  it("returns the string value for const char*", [] {
    const char* s = "Hello, 世界!";
    expect(inspect(s)).to(eq("Hello, 世界!"));
  });

  it("returns the value for string", [] {
    string s = "你好, world!";
    expect(inspect(s)).to(eq("你好, world!"));
  });

  it("returns the type name for arbitrary types", [] {
    class AbstractUserServiceProviderModule {
    } abstract_user_service_provider_module;
    expect(inspect(abstract_user_service_provider_module))
        .to(contain("AbstractUserServiceProviderModule"));
  });
});

}  // namespace support
}  // namespace spec
