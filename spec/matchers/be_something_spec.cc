#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::BeSomething;
using ccspec::matchers::be;
using ccspec::matchers::match;

namespace spec {
namespace matchers {

auto be_something_spec = describe("BeSomething", [] {
  describe("::instance", [] {
    it("returns the same BeSomething instance as be", [] {
      expect(BeSomething::instance()).to(be(be));
    });

    it("returns a singleton", [] {
      expect(BeSomething::instance()).to(be(BeSomething::instance()));
    });
  });

  // Other methods of BeSomething are all specified in other matcher specs.
});

}  // namespace matchers
}  // namespace spec
