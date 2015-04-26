#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::BeFalsey;
using ccspec::matchers::be;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;

namespace spec {
namespace matchers {

auto be_falsey_spec = describe("BeFalsey", [] {
  describe("::instance", [] {
    it("returns the same BeFalsey instance as be_falsey", [] {
      expect(BeFalsey::instance()).to(be(be_falsey));
    });

    it("returns a singleton", [] {
      expect(BeFalsey::instance()).to(be(BeFalsey::instance()));
    });
  });

  it("matches if a const temporary bool is false", [] {
    expect(be_falsey.match(false)).to(be_truthy);
  });

  it("matches if a bool is false", [] {
    bool b = false;
    expect(be_falsey.match(b)).to(be_truthy);
  });

  it("does not match if a bool is true", [] {
    bool b = true;
    expect(be_falsey.match(b)).to(be_falsey);
  });

  it("matches if a const temporary char is falsey", [] {
    expect(be_falsey.match('\0')).to(be_truthy);
  });

  it("matches if a char is falsey", [] {
    char c = '\0';
    expect(be_falsey.match(c)).to(be_truthy);
  });

  it("does not match if a char is truthy", [] {
    char c = 'x';
    expect(be_falsey.match(c)).to(be_falsey);
  });

  it("matches if a const temporary int is falsey", [] {
    expect(be_falsey.match(0)).to(be_truthy);
  });

  it("matches if an int is falsey", [] {
    int i = 0;
    expect(be_falsey.match(i)).to(be_truthy);
  });

  it("does not match if an int is truthy", [] {
    int i = 42;
    expect(be_falsey.match(i)).to(be_falsey);
  });

  it("matches if a const temporary double is falsey", [] {
    expect(be_falsey.match(0.0)).to(be_truthy);
  });

  it("matches if a double is falsey", [] {
    double d = 0.0;
    expect(be_falsey.match(d)).to(be_truthy);
  });

  it("does not match if a double is truthy", [] {
    double d = 3.14;
    expect(be_falsey.match(d)).to(be_falsey);
  });

  describe("#desc", [] {
    it("says 'be falsey'", [] {
      expect(be_falsey.desc()).to(eq("be falsey"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
