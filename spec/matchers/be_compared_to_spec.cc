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
using ccspec::matchers::be;
using ccspec::matchers::eq;

namespace spec {
namespace matchers {

auto be_compared_to_spec = describe("BeComparedTo", [] {
  context("with < comparator", [] {
    it("matches if actual const temp char is < expected", [] {
      expect((be < 'b').match('a')).to(be_truthy);
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'x', c1 = 'y';
      expect((be < c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'b', c1 = 'a';
      expect((be < c1).match(c0)).to(be_falsey);
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be < c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is < expected", [] {
      expect((be < 42).match(41)).to(be_truthy);
    });

    it("matches if actual int is < expected", [] {
      int i0 = 32767, i1 = 32768;
      expect((be < i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 42, i1 = -42;
      expect((be < i1).match(i0)).to(be_falsey);
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be < i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is < expected", [] {
      expect((be < 3.14).match(3.1)).to(be_truthy);
    });

    it("matches if actual double is < expected", [] {
      double d0 = 8.86, d1 = 8.87;
      expect((be < d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 3.14, d1 = -3.14;
      expect((be < d1).match(d0)).to(be_falsey);
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be < d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is < expected", [] {
      expect((be < string("abc")).match(string("ab"))).to(be_truthy);
    });

    it("matches if actual string is < expected", [] {
      string s0 = "xyy", s1 = "xyz";
      expect((be < s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "abc", s1 = "abb";
      expect((be < s1).match(s0)).to(be_falsey);
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be < s1).match(s0)).to(be_falsey);
    });
  });

  context("with <= comparator", [] {
    it("matches if actual const temp char is <= expected", [] {
      expect((be <= 'b').match('a')).to(be_truthy);
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'x', c1 = 'y';
      expect((be <= c1).match(c0)).to(be_truthy);
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'x', c1 = 'x';
      expect((be <= c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'b', c1 = 'a';
      expect((be <= c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is <= expected", [] {
      expect((be <= 42).match(41)).to(be_truthy);
    });

    it("matches if actual int is < expected", [] {
      int i0 = 32767, i1 = 32768;
      expect((be <= i1).match(i0)).to(be_truthy);
    });

    it("matches if actual int is == expected", [] {
      int i0 = 32767, i1 = 32767;
      expect((be <= i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 42, i1 = -42;
      expect((be <= i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is <= expected", [] {
      expect((be <= 3.14).match(3.1)).to(be_truthy);
    });

    it("matches if actual double is < expected", [] {
      double d0 = 8.86, d1 = 8.87;
      expect((be <= d1).match(d0)).to(be_truthy);
    });

    it("matches if actual double is == expected", [] {
      double d0 = 8.86, d1 = 8.86;
      expect((be <= d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 3.14, d1 = -3.14;
      expect((be <= d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is <= expected", [] {
      expect((be <= string("abc")).match(string("ab"))).to(be_truthy);
    });

    it("matches if actual string is < expected", [] {
      string s0 = "xyy", s1 = "xyz";
      expect((be <= s1).match(s0)).to(be_truthy);
    });

    it("matches if actual string is == expected", [] {
      string s0 = "xyz", s1 = "xyz";
      expect((be <= s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "abc", s1 = "abb";
      expect((be <= s1).match(s0)).to(be_falsey);
    });
  });

  context("with > comparator", [] {
    it("matches if actual const temp char is > expected", [] {
      expect((be > 'a').match('b')).to(be_truthy);
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be > c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be > c1).match(c0)).to(be_falsey);
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be > c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is > expected", [] {
      expect((be > 41).match(42)).to(be_truthy);
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be > i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be > i1).match(i0)).to(be_falsey);
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be > i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is > expected", [] {
      expect((be > 3.1).match(3.14)).to(be_truthy);
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be > d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be > d1).match(d0)).to(be_falsey);
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be > d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is > expected", [] {
      expect((be > string("ab")).match(string("abc"))).to(be_truthy);
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be > s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be > s1).match(s0)).to(be_falsey);
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be > s1).match(s0)).to(be_falsey);
    });
  });

  context("with >= comparator", [] {
    it("matches if actual const temp char is >= expected", [] {
      expect((be >= 'a').match('b')).to(be_truthy);
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be >= c1).match(c0)).to(be_truthy);
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be >= c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be >= c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is >= expected", [] {
      expect((be >= 41).match(42)).to(be_truthy);
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be >= i1).match(i0)).to(be_truthy);
    });

    it("matches if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be >= i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be >= i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is >= expected", [] {
      expect((be >= 3.1).match(3.14)).to(be_truthy);
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be >= d1).match(d0)).to(be_truthy);
    });

    it("matches if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be >= d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be >= d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is >= expected", [] {
      expect((be >= string("ab")).match(string("abc"))).to(be_truthy);
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be >= s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be >= s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be >= s1).match(s0)).to(be_falsey);
    });
  });

  context("with == comparator", [] {
    it("matches if actual const temp char is == expected", [] {
      expect((be == 'a').match('a')).to(be_truthy);
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be == c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be == c1).match(c0)).to(be_falsey);
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be == c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is == expected", [] {
      expect((be == 42).match(42)).to(be_truthy);
    });

    it("matches if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be == i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be == i1).match(i0)).to(be_falsey);
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be == i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is == expected", [] {
      expect((be == 3.14).match(3.14)).to(be_truthy);
    });

    it("matches if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be == d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be == d1).match(d0)).to(be_falsey);
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be == d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is == expected", [] {
      expect((be == string("abc")).match(string("abc"))).to(be_truthy);
    });

    it("matches if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be == s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be == s1).match(s0)).to(be_falsey);
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be == s1).match(s0)).to(be_falsey);
    });
  });

  context("with != comparator", [] {
    it("matches if actual const temp char is != expected", [] {
      expect((be != 'a').match('b')).to(be_truthy);
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be != c1).match(c0)).to(be_truthy);
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be != c1).match(c0)).to(be_truthy);
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be != c1).match(c0)).to(be_falsey);
    });

    it("matches if actual const temp int is != expected", [] {
      expect((be != 42).match(43)).to(be_truthy);
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be != i1).match(i0)).to(be_truthy);
    });

    it("matches if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be != i1).match(i0)).to(be_truthy);
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be != i1).match(i0)).to(be_falsey);
    });

    it("matches if actual const temp double is != expected", [] {
      expect((be != 3.14).match(3.141)).to(be_truthy);
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be != d1).match(d0)).to(be_truthy);
    });

    it("matches if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be != d1).match(d0)).to(be_truthy);
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be != d1).match(d0)).to(be_falsey);
    });

    it("matches if actual const temp string is != expected", [] {
      expect((be != string("abd")).match(string("abc"))).to(be_truthy);
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be != s1).match(s0)).to(be_truthy);
    });

    it("matches if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be != s1).match(s0)).to(be_truthy);
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be != s1).match(s0)).to(be_falsey);
    });
  });

  context("when used for arbitrary types", [] {
    class T {
     public:
      explicit T(int i) : i_(i) {}

      bool operator <(const T& t) const {
        return i_ < t.i_;
      }

      bool operator <=(const T& t) const {
        return i_ <= t.i_;
      }

      bool operator >(const T& t) const {
        return i_ > t.i_;
      }

      bool operator >=(const T& t) const {
        return i_ >= t.i_;
      }

      bool operator ==(const T& t) const {
        return i_ == t.i_;
      }

      bool operator !=(const T& t) const {
        return i_ != t.i_;
      }

     private:
      int i_;
    };

    context("with < comparator", [] {
      it("matches if actual const temp instance is < expected", [] {
        expect((be < T(3)).match(T(2))).to(be_truthy);
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be < t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be < t1).match(t0)).to(be_falsey);
      });

      it("does not match if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be < t1).match(t0)).to(be_falsey);
      });
    });

    context("with <= comparator", [] {
      it("matches if actual const temp instance is <= expected", [] {
        expect((be <= T(3)).match(T(2))).to(be_truthy);
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be <= t1).match(t0)).to(be_truthy);
      });

      it("matches if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be <= t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be <= t1).match(t0)).to(be_falsey);
      });
    });

    context("with > comparator", [] {
      it("matches if actual const temp instance is > expected", [] {
        expect((be > T(2)).match(T(3))).to(be_truthy);
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be > t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be > t1).match(t0)).to(be_falsey);
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be > t1).match(t0)).to(be_falsey);
      });
    });

    context("with >= comparator", [] {
      it("matches if actual const temp instance is >= expected", [] {
        expect((be >= T(2)).match(T(3))).to(be_truthy);
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be >= t1).match(t0)).to(be_truthy);
      });

      it("matches if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be >= t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be >= t1).match(t0)).to(be_falsey);
      });
    });

    context("with == comparator", [] {
      it("matches if actual const temp instance is == expected", [] {
        expect((be == T(2)).match(T(2))).to(be_truthy);
      });

      it("matches if actual instance is == expected", [] {
        T t0(0), t1(0);
        expect((be == t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be == t1).match(t0)).to(be_falsey);
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be == t1).match(t0)).to(be_falsey);
      });
    });

    context("with != comparator", [] {
      it("matches if actual const temp instance is != expected", [] {
        expect((be != T(2)).match(T(1))).to(be_truthy);
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be != t1).match(t0)).to(be_truthy);
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be != t1).match(t0)).to(be_truthy);
      });

      it("does not match if actual instance is == expected", [] {
        T t0(0), t1(0);
        expect((be != t1).match(t0)).to(be_falsey);
      });
    });
  });

  describe("#desc", [] {
    context("with < comparator", [] {
      it("says '< $c' when expecting char", [] {
        expect((be < 'x').desc()).to(eq("be < x"));
      });

      it("says '< $i' when expecting int", [] {
        expect((be < 42).desc()).to(eq("be < 42"));
      });

      it("says '< $d' when expecting double", [] {
        expect((be < 3.14).desc()).to(eq("be < 3.14"));
      });

      it("says '< $s' when expecting string", [] {
        expect((be < string("test")).desc()).to(eq("be < test"));
      });
    });
  });
});

}  // namespace matchers
}  // namespace spec
