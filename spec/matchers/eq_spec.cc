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
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;

namespace spec {
namespace matchers {

auto eq_spec = describe("Eq", [] {
  it("matches if two const temporary bools are equal", [] {
    expect(eq(false).match(false)).to(be_truthy);
  });

  it("matches if two bools are equal", [] {
    bool b0, b1;
    b0 = b1 = true;
    expect(eq(b0).match(b1)).to(be_truthy);
  });

  it("does not match if two bools are not equal", [] {
    bool b0 = true, b1 = false;
    expect(eq(b0).match(b1)).to(be_falsey);
  });

  it("matches if two const temporary chars are equal", [] {
    expect(eq('x').match('x')).to(be_truthy);
  });

  it("matches if two chars are equal", [] {
    char c0, c1;
    c0 = c1 = 'z';
    expect(eq(c0).match(c1)).to(be_truthy);
  });

  it("does not match if two chars are not equal", [] {
    char c0 = 'x', c1 = 'y';
    expect(eq(c0).match(c1)).to(be_falsey);
  });

  it("matches if two const temporary ints are equal", [] {
    expect(eq(42).match(42)).to(be_truthy);
  });

  it("matches if two ints are equal", [] {
    int i0, i1;
    i0 = i1 = 42;
    expect(eq(i0).match(i1)).to(be_truthy);
  });

  it("does not match if two ints are not equal", [] {
    int i0 = 42, i1 = 43;
    expect(eq(i0).match(i1)).to(be_falsey);
  });

  it("matches if two const temporary doubles are equal", [] {
    expect(eq(3.14).match(3.14)).to(be_truthy);
  });

  it("matches if two doubles are equal", [] {
    double d0, d1;
    d0 = d1 = 2.718;
    expect(eq(d0).match(d1)).to(be_truthy);
  });

  it("does not match if two doubles are not equal", [] {
    double d0 = 3.14, d1 = 2.718;
    expect(eq(d0).match(d1)).to(be_falsey);
  });


  it("matches if two const temporary char* point to the same string", [] {
    expect(eq("foo").match("foo")).to(be_truthy);
  });

  it("matches if two char* point to the same string", [] {
    const char* str0 = "test";
    const char* str1 = "test";
    expect(eq(str0).match(str1)).to(be_truthy);
  });

  it("does not match if two char* point to different string", [] {
    const char* str0 = "test";
    const char* str1 = "spec";
    expect(eq(str0).match(str1)).to(be_falsey);
  });

  it("does not match if two char* point to different copies of the same string",
     [] {
    const char* str0 = "test";
    char str1[] = "test";
    expect(eq(str0).match(str1)).to(be_falsey);
  });

  it("matches if two const temporary std::string are equal", [] {
    expect(eq(string("test")).match(string("test"))).to(be_truthy);
  });

  it("matches if two std::string are equal", [] {
    string str0 = "test";
    string str1 = "test";
    expect(eq(str0).match(str1)).to(be_truthy);
  });

  it("does not match if two std::string are not equal", [] {
    string str0 = "test";
    string str1 = "spec";
    expect(eq(str0).match(str1)).to(be_falsey);
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
    } t0(0), t1(2), t3(0);

    it("matches if two const temporary instances of them are equal", [] {
      expect(eq(T(3)).match(T(3))).to(be_truthy);
    });

    it("matches if two instances of them are equal", [t0, t3] {
      expect(eq(t0).match(t3)).to(be_truthy);
    });

    it("does not match if two instances of them are not equal", [t1, t3] {
      expect(eq(t1).match(t3)).to(be_falsey);
    });
  });

  describe("desc", [] {
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

    it("says 'equal $s' when expecting std::string", [] {
      expect(eq(string("test")).desc()).to(eq("equal test"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
