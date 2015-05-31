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

auto be_compared_to_spec = describe("BeComparedTo", [] {
  context("with < comparator", [] {
    it("matches if actual const temp char is < expected", [] {
      expect((be < 'b')).to(match('a'));
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'x', c1 = 'y';
      expect((be < c1)).to(match(c0));
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'b', c1 = 'a';
      expect((be < c1)).notTo(match(c0));
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be < c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is < expected", [] {
      expect((be < 42)).to(match(41));
    });

    it("matches if actual int is < expected", [] {
      int i0 = 32767, i1 = 32768;
      expect((be < i1)).to(match(i0));
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 42, i1 = -42;
      expect((be < i1)).notTo(match(i0));
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be < i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is < expected", [] {
      expect((be < 3.14)).to(match(3.1));
    });

    it("matches if actual double is < expected", [] {
      double d0 = 8.86, d1 = 8.87;
      expect((be < d1)).to(match(d0));
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 3.14, d1 = -3.14;
      expect((be < d1)).notTo(match(d0));
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be < d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is < expected", [] {
      expect((be < string("abc"))).to(match(string("ab")));
    });

    it("matches if actual string is < expected", [] {
      string s0 = "xyy", s1 = "xyz";
      expect((be < s1)).to(match(s0));
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "abc", s1 = "abb";
      expect((be < s1)).notTo(match(s0));
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be < s1)).notTo(match(s0));
    });
  });

  context("with <= comparator", [] {
    it("matches if actual const temp char is <= expected", [] {
      expect((be <= 'b')).to(match('a'));
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'x', c1 = 'y';
      expect((be <= c1)).to(match(c0));
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'x', c1 = 'x';
      expect((be <= c1)).to(match(c0));
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'b', c1 = 'a';
      expect((be <= c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is <= expected", [] {
      expect((be <= 42)).to(match(41));
    });

    it("matches if actual int is < expected", [] {
      int i0 = 32767, i1 = 32768;
      expect((be <= i1)).to(match(i0));
    });

    it("matches if actual int is == expected", [] {
      int i0 = 32767, i1 = 32767;
      expect((be <= i1)).to(match(i0));
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 42, i1 = -42;
      expect((be <= i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is <= expected", [] {
      expect((be <= 3.14)).to(match(3.1));
    });

    it("matches if actual double is < expected", [] {
      double d0 = 8.86, d1 = 8.87;
      expect((be <= d1)).to(match(d0));
    });

    it("matches if actual double is == expected", [] {
      double d0 = 8.86, d1 = 8.86;
      expect((be <= d1)).to(match(d0));
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 3.14, d1 = -3.14;
      expect((be <= d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is <= expected", [] {
      expect((be <= string("abc"))).to(match(string("ab")));
    });

    it("matches if actual string is < expected", [] {
      string s0 = "xyy", s1 = "xyz";
      expect((be <= s1)).to(match(s0));
    });

    it("matches if actual string is == expected", [] {
      string s0 = "xyz", s1 = "xyz";
      expect((be <= s1)).to(match(s0));
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "abc", s1 = "abb";
      expect((be <= s1)).notTo(match(s0));
    });
  });

  context("with > comparator", [] {
    it("matches if actual const temp char is > expected", [] {
      expect((be > 'a')).to(match('b'));
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be > c1)).to(match(c0));
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be > c1)).notTo(match(c0));
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be > c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is > expected", [] {
      expect((be > 41)).to(match(42));
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be > i1)).to(match(i0));
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be > i1)).notTo(match(i0));
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be > i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is > expected", [] {
      expect((be > 3.1)).to(match(3.14));
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be > d1)).to(match(d0));
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be > d1)).notTo(match(d0));
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be > d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is > expected", [] {
      expect((be > string("ab"))).to(match(string("abc")));
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be > s1)).to(match(s0));
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be > s1)).notTo(match(s0));
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be > s1)).notTo(match(s0));
    });
  });

  context("with >= comparator", [] {
    it("matches if actual const temp char is >= expected", [] {
      expect((be >= 'a')).to(match('b'));
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be >= c1)).to(match(c0));
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be >= c1)).to(match(c0));
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be >= c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is >= expected", [] {
      expect((be >= 41)).to(match(42));
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be >= i1)).to(match(i0));
    });

    it("matches if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be >= i1)).to(match(i0));
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be >= i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is >= expected", [] {
      expect((be >= 3.1)).to(match(3.14));
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be >= d1)).to(match(d0));
    });

    it("matches if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be >= d1)).to(match(d0));
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be >= d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is >= expected", [] {
      expect((be >= string("ab"))).to(match(string("abc")));
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be >= s1)).to(match(s0));
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be >= s1)).to(match(s0));
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be >= s1)).notTo(match(s0));
    });
  });

  context("with == comparator", [] {
    it("matches if actual const temp char is == expected", [] {
      expect((be == 'a')).to(match('a'));
    });

    it("matches if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be == c1)).to(match(c0));
    });

    it("does not match if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be == c1)).notTo(match(c0));
    });

    it("does not match if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be == c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is == expected", [] {
      expect((be == 42)).to(match(42));
    });

    it("matches if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be == i1)).to(match(i0));
    });

    it("does not match if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be == i1)).notTo(match(i0));
    });

    it("does not match if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be == i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is == expected", [] {
      expect((be == 3.14)).to(match(3.14));
    });

    it("matches if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be == d1)).to(match(d0));
    });

    it("does not match if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be == d1)).notTo(match(d0));
    });

    it("does not match if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be == d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is == expected", [] {
      expect((be == string("abc"))).to(match(string("abc")));
    });

    it("matches if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be == s1)).to(match(s0));
    });

    it("does not match if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be == s1)).notTo(match(s0));
    });

    it("does not match if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be == s1)).notTo(match(s0));
    });
  });

  context("with != comparator", [] {
    it("matches if actual const temp char is != expected", [] {
      expect((be != 'a')).to(match('b'));
    });

    it("matches if actual char is > expected", [] {
      char c0 = 'y', c1 = 'x';
      expect((be != c1)).to(match(c0));
    });

    it("matches if actual char is < expected", [] {
      char c0 = 'a', c1 = 'b';
      expect((be != c1)).to(match(c0));
    });

    it("does not match if actual char is == expected", [] {
      char c0 = 'b', c1 = 'b';
      expect((be != c1)).notTo(match(c0));
    });

    it("matches if actual const temp int is != expected", [] {
      expect((be != 42)).to(match(43));
    });

    it("matches if actual int is > expected", [] {
      int i0 = 32768, i1 = 32767;
      expect((be != i1)).to(match(i0));
    });

    it("matches if actual int is < expected", [] {
      int i0 = -42, i1 = 42;
      expect((be != i1)).to(match(i0));
    });

    it("does not match if actual int is == expected", [] {
      int i0 = 42, i1 = 42;
      expect((be != i1)).notTo(match(i0));
    });

    it("matches if actual const temp double is != expected", [] {
      expect((be != 3.14)).to(match(3.141));
    });

    it("matches if actual double is > expected", [] {
      double d0 = 8.87, d1 = 8.86;
      expect((be != d1)).to(match(d0));
    });

    it("matches if actual double is < expected", [] {
      double d0 = -3.14, d1 = 3.14;
      expect((be != d1)).to(match(d0));
    });

    it("does not match if actual double is == expected", [] {
      double d0 = 3.14, d1 = 3.14;
      expect((be != d1)).notTo(match(d0));
    });

    it("matches if actual const temp string is != expected", [] {
      expect((be != string("abd"))).to(match(string("abc")));
    });

    it("matches if actual string is > expected", [] {
      string s0 = "xyz", s1 = "xyy";
      expect((be != s1)).to(match(s0));
    });

    it("matches if actual string is < expected", [] {
      string s0 = "abb", s1 = "abc";
      expect((be != s1)).to(match(s0));
    });

    it("does not match if actual string is == expected", [] {
      string s0 = "abc", s1 = "abc";
      expect((be != s1)).notTo(match(s0));
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
        expect((be < T(3))).to(match(T(2)));
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be < t1)).to(match(t0));
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be < t1)).notTo(match(t0));
      });

      it("does not match if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be < t1)).notTo(match(t0));
      });
    });

    context("with <= comparator", [] {
      it("matches if actual const temp instance is <= expected", [] {
        expect((be <= T(3))).to(match(T(2)));
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be <= t1)).to(match(t0));
      });

      it("matches if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be <= t1)).to(match(t0));
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be <= t1)).notTo(match(t0));
      });
    });

    context("with > comparator", [] {
      it("matches if actual const temp instance is > expected", [] {
        expect((be > T(2))).to(match(T(3)));
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be > t1)).to(match(t0));
      });

      it("does not match if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be > t1)).notTo(match(t0));
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be > t1)).notTo(match(t0));
      });
    });

    context("with >= comparator", [] {
      it("matches if actual const temp instance is >= expected", [] {
        expect((be >= T(2))).to(match(T(3)));
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be >= t1)).to(match(t0));
      });

      it("matches if actual instance is == expected", [] {
        T t0(1), t1(1);
        expect((be >= t1)).to(match(t0));
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be >= t1)).notTo(match(t0));
      });
    });

    context("with == comparator", [] {
      it("matches if actual const temp instance is == expected", [] {
        expect((be == T(2))).to(match(T(2)));
      });

      it("matches if actual instance is == expected", [] {
        T t0(0), t1(0);
        expect((be == t1)).to(match(t0));
      });

      it("does not match if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be == t1)).notTo(match(t0));
      });

      it("does not match if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be == t1)).notTo(match(t0));
      });
    });

    context("with != comparator", [] {
      it("matches if actual const temp instance is != expected", [] {
        expect((be != T(2))).to(match(T(1)));
      });

      it("matches if actual instance is > expected", [] {
        T t0(1), t1(0);
        expect((be != t1)).to(match(t0));
      });

      it("matches if actual instance is < expected", [] {
        T t0(0), t1(1);
        expect((be != t1)).to(match(t0));
      });

      it("does not match if actual instance is == expected", [] {
        T t0(0), t1(0);
        expect((be != t1)).notTo(match(t0));
      });
    });
  });

  describe("#desc", [] {
    context("with < comparator", [] {
      it("says 'be < $c' when expecting char", [] {
        expect((be < 'x').desc()).to(eq("be < x"));
      });

      it("says 'be < $i' when expecting int", [] {
        expect((be < 42).desc()).to(eq("be < 42"));
      });

      it("says 'be < $d' when expecting double", [] {
        expect((be < 3.14).desc()).to(eq("be < 3.14"));
      });

      it("says 'be < $s' when expecting string", [] {
        expect((be < string("test")).desc()).to(eq("be < test"));
      });
    });

    context("with <= comparator", [] {
      it("says 'be <= $c' when expecting char", [] {
        expect((be <= 'x').desc()).to(eq("be <= x"));
      });

      it("says 'be <= $i' when expecting int", [] {
        expect((be <= 42).desc()).to(eq("be <= 42"));
      });

      it("says 'be <= $d' when expecting double", [] {
        expect((be <= 3.14).desc()).to(eq("be <= 3.14"));
      });

      it("says 'be <= $s' when expecting string", [] {
        expect((be <= string("test")).desc()).to(eq("be <= test"));
      });
    });

    context("with > comparator", [] {
      it("says 'be > $c' when expecting char", [] {
        expect((be > 'x').desc()).to(eq("be > x"));
      });

      it("says 'be > $i' when expecting int", [] {
        expect((be > 42).desc()).to(eq("be > 42"));
      });

      it("says 'be > $d' when expecting double", [] {
        expect((be > 3.14).desc()).to(eq("be > 3.14"));
      });

      it("says 'be > $s' when expecting string", [] {
        expect((be > string("test")).desc()).to(eq("be > test"));
      });
    });

    context("with >= comparator", [] {
      it("says 'be >= $c' when expecting char", [] {
        expect((be >= 'x').desc()).to(eq("be >= x"));
      });

      it("says 'be >= $i' when expecting int", [] {
        expect((be >= 42).desc()).to(eq("be >= 42"));
      });

      it("says 'be >= $d' when expecting double", [] {
        expect((be >= 3.14).desc()).to(eq("be >= 3.14"));
      });

      it("says 'be >= $s' when expecting string", [] {
        expect((be >= string("test")).desc()).to(eq("be >= test"));
      });
    });

    context("with == comparator", [] {
      it("says 'be equal to $c' when expecting char", [] {
        expect((be == 'x').desc()).to(eq("be equal to x"));
      });

      it("says 'be equal to $i' when expecting int", [] {
        expect((be == 42).desc()).to(eq("be equal to 42"));
      });

      it("says 'be equal to $d' when expecting double", [] {
        expect((be == 3.14).desc()).to(eq("be equal to 3.14"));
      });

      it("says 'be equal to $s' when expecting string", [] {
        expect((be == string("test")).desc()).to(eq("be equal to test"));
      });
    });

    context("with != comparator", [] {
      it("says 'be not equal to $c' when expecting char", [] {
        expect((be != 'x').desc()).to(eq("be not equal to x"));
      });

      it("says 'be not equal to $i' when expecting int", [] {
        expect((be != 42).desc()).to(eq("be not equal to 42"));
      });

      it("says 'be not equal to $d' when expecting double", [] {
        expect((be != 3.14).desc()).to(eq("be not equal to 3.14"));
      });

      it("says 'be not equal to $s' when expecting string", [] {
        expect((be != string("test")).desc()).to(eq("be not equal to test"));
      });
    });
  });
});

}  // namespace matchers
}  // namespace spec
