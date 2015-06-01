#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using std::string;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto match_spec = describe("Match", [] {
  class T {
   public:
    explicit T(bool b) : b_(b) {}
    explicit T(char c) : c_(c) {}
    explicit T(int i) : i_(i) {}
    explicit T(double d) : d_(d) {}
    explicit T(const char* s) : s_(s) {}
    explicit T(string s) : str_(s) {}

    bool match(bool b) const {
      return b_ == b;
    }

    bool match(char c) const {
      return c_ == c;
    }

    bool match(int i) const {
      return i_ == i;
    }

    bool match(double d) const {
      return d_ == d;
    }

    bool match(const char* s) const {
      return s_ == s;
    }

    bool match(string s) const {
      return str_ == s;
    }

   private:
    bool b_;
    char c_;
    int i_;
    double d_;
    const char* s_;
    string str_;
  };

  it("matches if a const temp instance matches a given const temp bool", [] {
    expect(match(true).match(T(true))).to(be_truthy);
  });

  it("matches if an instance matches a given bool", [] {
    T t(true);
    bool b = true;
    expect(match(b).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given bool", [] {
    T t(false);
    bool b = true;
    expect(match(b).match(t)).to(be_falsey);
  });

  it("matches if a const temp instance matches a given const temp char", [] {
    expect(match('x').match(T('x'))).to(be_truthy);
  });

  it("matches if an instance matches a given char", [] {
    T t('x');
    char c = 'x';
    expect(match(c).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given char", [] {
    T t('y');
    char c = 'x';
    expect(match(c).match(t)).to(be_falsey);
  });

  it("matches if a const temp instance matches a given const temp int", [] {
    expect(match(3).match(T(3))).to(be_truthy);
  });

  it("matches if an instance matches a given int", [] {
    T t(1);
    int i = 1;
    expect(match(i).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given int", [] {
    T t(1);
    int i = 2;
    expect(match(i).match(t)).to(be_falsey);
  });

  it("matches if a const temp instance matches a given const temp double", [] {
    expect(match(3.14).match(T(3.14))).to(be_truthy);
  });

  it("matches if an instance matches a given double", [] {
    T t(3.14);
    double d = 3.14;
    expect(match(d).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given double", [] {
    T t(3.14);
    double d = 2.138;
    expect(match(d).match(t)).to(be_falsey);
  });

  it("matches if a const temp instance matches a given const temp char*", [] {
    expect(match("xyz").match(T("xyz"))).to(be_truthy);
  });

  it("matches if an instance matches a given char*", [] {
    T t("xyz");
    const char* s = "xyz";
    expect(match(s).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given char*", [] {
    T t("xyz");
    const char* s = "abc";
    expect(match(s).match(t)).to(be_falsey);
  });

  it("matches if a const temp instance matches a given const temp string", [] {
    expect(match(string("xyz")).match(T(string("xyz")))).to(be_truthy);
  });

  it("matches if an instance matches a given string", [] {
    T t(string("xyz"));
    string s = "xyz";
    expect(match(s).match(t)).to(be_truthy);
  });

  it("doesn't match if an instance doesn't match a given string", [] {
    T t(string("xyz"));
    string s = "abc";
    expect(match(s).match(t)).to(be_falsey);
  });

  describe("#desc", [] {
    it("says 'match $b' when expecting bool", [] {
      expect(match(true).desc()).to(eq("match true"));
    });

    it("says 'match $c' when expecting char", [] {
      expect(match('x').desc()).to(eq("match x"));
    });

    it("says 'match $i' when expecting int", [] {
      expect(match(42).desc()).to(eq("match 42"));
    });

    it("says 'match $d' when expecting double", [] {
      expect(match(3.14).desc()).to(eq("match 3.14"));
    });

    it("says 'match $s' when expecting char*", [] {
      expect(match("test").desc()).to(eq("match test"));
    });

    it("says 'match $s' when expecting string", [] {
      expect(match(string("test")).desc()).to(eq("match test"));
    });
  });
});

}  // namespace matchers
}  // namespace spec
