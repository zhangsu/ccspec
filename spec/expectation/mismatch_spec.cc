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
using ccspec::expectation::Mismatch;
using ccspec::matchers::BeComparedTo;
using ccspec::matchers::Eq;
using ccspec::matchers::be;
using ccspec::matchers::eq;

auto mismatch_spec = describe("Mismatch", [] {
  describe("#what", [] {
    it("says '$x should equal $y' for Eq matcher", [] {
      Mismatch<int, Eq<int>> mismatch(42, eq(43));
      expect(string(mismatch.what())).to(eq("42 should equal 43"));
    });

    it("says '$x should be <= $y' for BeComparedTo matcher with <=", [] {
      Mismatch<int, BeComparedTo<int>> mismatch(42, be <= 41);
      expect(string(mismatch.what())).to(eq("42 should be <= 41"));
    });
  });
});

}  // namespace expectation
}  // namespace spec
