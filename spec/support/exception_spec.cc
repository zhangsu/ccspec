#include <cstring>
#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"
#include "ccspec/support/exception.h"

namespace spec {
namespace support {

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::eq;

auto exception_spec = describe("Exception", [] {
  class Exception : public ccspec::support::Exception {
   public:
    explicit Exception(string desc) : ccspec::support::Exception(desc) {}
  };

  describe("#what", [] {
    it("returns the exception description", [] {
      Exception e("foo");
      expect(strcmp(e.what(), "foo")).to(eq(0));
    });
  });
});

}  // namespace support
}  // namespace spec
