#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::BeFalsey;
using ccspec::matchers::be;
using ccspec::matchers::be_falsey;
using ccspec::matchers::eq;
using ccspec::matchers::match;

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

  it("matches if a const temp bool is false", [] {
    expect(be_falsey).to(match(false));
  });

  it("matches if a bool is false", [] {
    bool b = false;
    expect(be_falsey).to(match(b));
  });

  it("does not match if a bool is true", [] {
    bool b = true;
    expect(be_falsey).notTo(match(b));
  });

  it("matches if a const temp char is falsey", [] {
    expect(be_falsey).to(match('\0'));
  });

  it("matches if a char is falsey", [] {
    char c = '\0';
    expect(be_falsey).to(match(c));
  });

  it("does not match if a char is truthy", [] {
    char c = 'x';
    expect(be_falsey).notTo(match(c));
  });

  it("matches if a const temp int is falsey", [] {
    expect(be_falsey).to(match(0));
  });

  it("matches if an int is falsey", [] {
    int i = 0;
    expect(be_falsey).to(match(i));
  });

  it("does not match if an int is truthy", [] {
    int i = 42;
    expect(be_falsey).notTo(match(i));
  });

  it("matches if a const temp double is falsey", [] {
    expect(be_falsey).to(match(0.0));
  });

  it("matches if a double is falsey", [] {
    double d = 0.0;
    expect(be_falsey).to(match(d));
  });

  it("does not match if a double is truthy", [] {
    double d = 3.14;
    expect(be_falsey).notTo(match(d));
  });

  describe("#desc", [] {
    it("says 'be falsey'", [] {
      expect(be_falsey.desc()).to(eq("be falsey"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
