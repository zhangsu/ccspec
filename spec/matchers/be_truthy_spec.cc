#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::BeTruthy;
using ccspec::matchers::be;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto be_truthy_spec = describe("BeTruthy", [] {
  describe("::instance", [] {
    it("returns the same BeTruthy instance as be_truthy", [] {
      expect(BeTruthy::instance()).to(be(be_truthy));
    });

    it("returns a singleton", [] {
      expect(BeTruthy::instance()).to(be(BeTruthy::instance()));
    });
  });

  it("matches if a const temp bool is true", [] {
    expect(be_truthy).to(match(true));
  });

  it("matches if a bool is true", [] {
    bool b = true;
    expect(be_truthy).to(match(b));
  });

  it("does not match if a bool is false", [] {
    bool b = false;
    expect(be_truthy).notTo(match(b));
  });

  it("matches if a const temp char is truthy", [] {
    expect(be_truthy).to(match('x'));
  });

  it("matches if a char is truthy", [] {
    char c = 'z';
    expect(be_truthy).to(match(c));
  });

  it("does not match if a char is falsey", [] {
    char c = '\0';
    expect(be_truthy).notTo(match(c));
  });

  it("matches if a const temp int is truthy", [] {
    expect(be_truthy).to(match(42));
  });

  it("matches if an int is truthy", [] {
    int i = 42;
    expect(be_truthy).to(match(i));
  });

  it("does not match if an int is falsey", [] {
    int i = 0;
    expect(be_truthy).notTo(match(i));
  });

  it("matches if a const temp double is truthy", [] {
    expect(be_truthy).to(match(3.14));
  });

  it("matches if a double is truthy", [] {
    double d = 3.14;
    expect(be_truthy).to(match(d));
  });

  it("does not match if a double is falsey", [] {
    double d = 0.0;
    expect(be_truthy).notTo(match(d));
  });

  describe("#desc", [] {
    it("says 'be truthy'", [] {
      expect(be_truthy.desc()).to(eq("be truthy"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
