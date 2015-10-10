#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

namespace spec {
namespace expectation {

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::expectation::UnexpectedMatch;
using ccspec::matchers::BeComparedTo;
using ccspec::matchers::Eq;
using ccspec::matchers::be;
using ccspec::matchers::eq;

auto unexpected_match_spec = describe("UnexpectedMatch", [] {
  describe("#what", [] {
    it("says '$x should not equal $y' for Eq matcher", [] {
      UnexpectedMatch<int, Eq<int>> unexpected_match(42, eq(42));
      expect(string(unexpected_match.what())).to(eq("42 should not equal 42"));
    });

    it("says '$x should not be <= $y' for BeComparedTo matcher with <=", [] {
      UnexpectedMatch<int, BeComparedTo<int>> unexpected_match(42, be <= 42);
      expect(string(unexpected_match.what())).to(eq("42 should not be <= 42"));
    });
  });
});

}  // namespace expectation
}  // namespace spec
