#include <ccspec.h>

using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;

namespace spec {
namespace matchers {

auto eq_spec = describe("Eq", [] {
    it("matches if two chars are equal", [] {
        char c0, c1;
        c0 = c1 = 42;
        expect(eq(c0).match(c1)).to(be_truthy);
    });

    it("does not match if two chars are not equal", [] {
        char c0 = 42, c1 = 43;
        expect(eq(c0).match(c1)).to(be_falsey);
    });
});

} // namespace matchers
} // namespace spec
