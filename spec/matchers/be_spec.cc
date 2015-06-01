#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using std::string;
using ccspec::core::before;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::be;
using ccspec::matchers::eq;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto be_spec = describe("Be", [] {
  it("matches if two bool references point to the same copy", [] {
    bool b0 = true;
    bool& b1 = b0;
    expect(be(b0)).to(match(b1));
  });

  it("doesn't match if two bool references point to different copies", [] {
    bool b0 = true;
    bool b1 = b0;
    expect(be(b0)).notTo(match(b1));
  });

  it("matches if two char references point to the same copy", [] {
    char c0 = 'z';
    char& c1 = c0;
    expect(be(c0)).to(match(c1));
  });

  it("doesn't match if two char references point to different copy", [] {
    char c0 = 'x';
    char c1 = c0;
    expect(be(c0)).notTo(match(c1));
  });

  it("matches if two int references point to the same copy", [] {
    int i0 = 42;
    int& i1 = i0;
    expect(be(i0)).to(match(i1));
  });

  it("doesn't match if two int references point to different copy", [] {
    int i0 = 42;
    int i1 = i0;
    expect(be(i0)).notTo(match(i1));
  });

  it("matches if two double references point to the same copy", [] {
    double d0 = 3.14;
    double& d1 = d0;
    expect(be(d0)).to(match(d1));
  });

  it("doesn't match if two double references point to different copy", [] {
    double d0 = 3.14;
    double d1 = d0;
    expect(be(d0)).notTo(match(d1));
  });

  it("matches if two char* references point to the same char* copy", [] {
    const char* str0 = "test";
    const char*& str1 = str0;
    expect(be(str0)).to(match(str1));
  });

  it("doesn't match if two char* references point to different char* copies",
     [] {
    const char* str0 = "test";
    const char* str1 = str0;
    expect(be(str0)).notTo(match(str1));
  });

  it("matches if two string references point to the same copy", [] {
    string str0 = "test";
    string& str1 = str0;
    expect(be(str0)).to(match(str1));
  });

  it("doesn't match if two string references point to different copies", [] {
    string str0 = "test";
    string str1 = str0;
    expect(be(str0)).notTo(match(str1));
  });

  context("when used for arbitrary types", [] {
    class T {};

    it("matches if two instances of them point to the same copy", [] {
      T t0;
      T& t1 = t0;
      expect(be(t0)).to(match(t1));
    });

    it("doesn't match if two instances of them point to different copies", [] {
      T t0;
      T t1 = t0;
      expect(be(t0)).notTo(match(t1));
    });
  });

  describe("#desc", [] {
    it("says 'be $b' when expecting bool", [] {
      expect(be(true).desc()).to(eq("be true"));
    });

    it("says 'be $c' when expecting char", [] {
      expect(be('x').desc()).to(eq("be x"));
    });

    it("says 'be $i' when expecting int", [] {
      expect(be(42).desc()).to(eq("be 42"));
    });

    it("says 'be $d' when expecting double", [] {
      expect(be(3.14).desc()).to(eq("be 3.14"));
    });

    it("says 'be $s' when expecting char*", [] {
      expect(be("test").desc()).to(eq("be test"));
    });

    it("says 'be $s' when expecting string", [] {
      expect(be(string("test")).desc()).to(eq("be test"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
