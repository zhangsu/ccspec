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
using ccspec::matchers::eq;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto eq_spec = describe("Eq", [] {
  it("matches if two const temp bools are equal", [] {
    expect(eq(false)).to(match(false));
  });

  it("matches if two bools are equal", [] {
    bool b0, b1;
    b0 = b1 = true;
    expect(eq(b0)).to(match(b1));
  });

  it("doesn't match if two bools are not equal", [] {
    bool b0 = true, b1 = false;
    expect(eq(b0)).notTo(match(b1));
  });

  it("matches if two const temp chars are equal", [] {
    expect(eq('x')).to(match('x'));
  });

  it("matches if two chars are equal", [] {
    char c0, c1;
    c0 = c1 = 'z';
    expect(eq(c0)).to(match(c1));
  });

  it("doesn't match if two chars are not equal", [] {
    char c0 = 'x', c1 = 'y';
    expect(eq(c0)).notTo(match(c1));
  });

  it("matches if two const temp ints are equal", [] {
    expect(eq(42)).to(match(42));
  });

  it("matches if two ints are equal", [] {
    int i0, i1;
    i0 = i1 = 42;
    expect(eq(i0)).to(match(i1));
  });

  it("doesn't match if two ints are not equal", [] {
    int i0 = 42, i1 = 43;
    expect(eq(i0)).notTo(match(i1));
  });

  it("matches if two const temp doubles are equal", [] {
    expect(eq(3.14)).to(match(3.14));
  });

  it("matches if two doubles are equal", [] {
    double d0, d1;
    d0 = d1 = 2.718;
    expect(eq(d0)).to(match(d1));
  });

  it("doesn't match if two doubles are not equal", [] {
    double d0 = 3.14, d1 = 2.718;
    expect(eq(d0)).notTo(match(d1));
  });


  it("matches if two const temp char* point to the same string", [] {
    expect(eq("foo")).to(match("foo"));
  });

  it("matches if two char* point to the same string", [] {
    const char* str0 = "test";
    const char* str1 = "test";
    expect(eq(str0)).to(match(str1));
  });

  it("doesn't match if two char* point to different strings", [] {
    const char* str0 = "test";
    const char* str1 = "spec";
    expect(eq(str0)).notTo(match(str1));
  });

  it("doesn't match if two char* point to different copies of the same string",
     [] {
    const char* str0 = "test";
    char str1[] = "test";
    expect(eq(str0)).notTo(match(str1));
  });

  it("matches if two const temp strings are equal", [] {
    expect(eq(string("test"))).to(match(string("test")));
  });

  it("matches if two strings are equal", [] {
    string str0 = "test", str1 = "test";
    expect(eq(str0)).to(match(str1));
  });

  it("doesn't match if two strings are not equal", [] {
    string str0 = "test", str1 = "spec";
    expect(eq(str0)).notTo(match(str1));
  });

  context("when used for arbitrary types", [] {
    class T {
     public:
      explicit T(int i) : i_(i) {}
      bool operator ==(const T& t) const {
        return i_ == t.i_;
      }

     private:
      int i_;
    };

    it("matches if two const temp instances of them are equal", [] {
      expect(eq(T(3))).to(match(T(3)));
    });

    it("matches if two instances of them are equal", [] {
      T t0(1), t1(1);
      expect(eq(t0)).to(match(t1));
    });

    it("doesn't match if two instances of them are not equal", [] {
      T t0(2), t1(1);
      expect(eq(t0)).notTo(match(t1));
    });
  });

  describe("#desc", [] {
    it("says 'equal $b' when expecting bool", [] {
      expect(eq(true).desc()).to(eq("equal true"));
    });

    it("says 'equal $c' when expecting char", [] {
      expect(eq('x').desc()).to(eq("equal x"));
    });

    it("says 'equal $i' when expecting int", [] {
      expect(eq(42).desc()).to(eq("equal 42"));
    });

    it("says 'equal $d' when expecting double", [] {
      expect(eq(3.14).desc()).to(eq("equal 3.14"));
    });

    it("says 'equal $s' when expecting char*", [] {
      expect(eq("test").desc()).to(eq("equal test"));
    });

    it("says 'equal $s' when expecting string", [] {
      expect(eq(string("test")).desc()).to(eq("equal test"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
