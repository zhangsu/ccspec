#include <ccspec.h>

using ccspec::core::context;
using ccspec::core::describe;
using ccspec::expect;
using ccspec::matchers::eq;

int main() {
    auto example_group = describe("User", [] {
        context("with email", [] {
        });

        context("without email", [] {
        });
    });

    expect(1).to(eq(1.01));

    delete example_group;

    return 0;
}
