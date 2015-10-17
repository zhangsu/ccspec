#include "ccspec/core.h"
#include "ccspec/core/execution_result.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

namespace spec {
namespace core {

using std::string;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::core::ExecutionResult;
using ccspec::matchers::eq;

auto execution_result_spec = describe("ExecutionResult", [] {
  it("initially has no exception", [] {
    ExecutionResult execution_result;
    // TODO(zhangsu): add a toBeNullptr matcher and use it here.
    expect(execution_result.exception()).to(eq(nullptr));
  });
});

}  // namespace core
}  // namespace spec
