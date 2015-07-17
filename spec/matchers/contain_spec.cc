#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::contain;
using ccspec::matchers::eq;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto contain_spec = describe("Contain", [] {
  it("matches if expected const char* is equal to given const char*", [] {
    expect(contain("abc")).to(match("abc"));
  });

  it("matches if expected const char* is prefix of given const char*", [] {
    expect(contain("abc")).to(match("abcde"));
  });

  it("matches if expected const char* is suffix of given const char*", [] {
    expect(contain("abc")).to(match("xyzabc"));
  });

  it("matches if expected const char* is substring of given const char*", [] {
    expect(contain("abc")).to(match("xyzabcdef"));
  });

  it("matches if expected string is equal to given string", [] {
    expect(contain(string("abc"))).to(match(string("abc")));
  });

  it("matches if expected string is prefix of given string", [] {
    expect(contain(string("abc"))).to(match(string("abcde")));
  });

  it("matches if expected string is suffix of given string", [] {
    expect(contain(string("abc"))).to(match(string("xyzabc")));
  });

  it("matches if expected string is substring of given string", [] {
    expect(contain(string("abc"))).to(match(string("xyzabcdef")));
  });

  it("matches if expected string is equal to given const char*", [] {
    expect(contain(string("abc"))).to(match("abc"));
  });

  it("matches if expected string is prefix of given const char*", [] {
    expect(contain(string("abc"))).to(match("abcde"));
  });

  it("matches if expected string is suffix of given const char*", [] {
    expect(contain(string("abc"))).to(match("xyzabc"));
  });

  it("matches if expected string is substring of given const char*", [] {
    expect(contain(string("abc"))).to(match("xyzabcdef"));
  });

  it("matches if expected const char* is equal to given string", [] {
    expect(contain("abc")).to(match(string("abc")));
  });

  it("matches if expected const char* is prefix of given string", [] {
    expect(contain("abc")).to(match(string("abcde")));
  });

  it("matches if expected const char* is suffix of given string", [] {
    expect(contain("abc")).to(match(string("xyzabc")));
  });

  it("matches if expected const char* is substring of given string", [] {
    expect(contain("abc")).to(match(string("xyzabcdef")));
  });

  describe("#desc", [] {
    it("says 'contain $s' when expecting const char*", [] {
      expect(contain("test").desc()).to(eq("contain test"));
    });

    it("says 'contain $s' when expecting string", [] {
      expect(contain(string("test")).desc()).to(eq("contain test"));
    });
  });
});

}  // namespace matchers
}  // namespace spec

