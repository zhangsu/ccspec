#include <exception>
#include <string>

#include "ccspec/core.h"
#include "ccspec/core/unexpected_throw.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

namespace spec {
namespace core {

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::core::UnexpectedThrow;
using ccspec::matchers::eq;

auto unexpected_throw_spec = describe("UnexpectedThrow", [] {
  describe("#what", [] {
    it("says 'Unexpected exception: ${cause.what()}'", [] {
      UnexpectedThrow unexpected_throw(std::invalid_argument("root cause"));
      string unexpected_throw_desc = unexpected_throw.what();
      expect(unexpected_throw_desc).to(eq("Unexpected exception: root cause"));
    });
  });
});

}  // namespace core
}  // namespace spec
