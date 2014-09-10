#include <iostream>
#include <ccspec.h>

using std::cout;
using std::endl;
using ccspec::core::before;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::core::example;
using ccspec::core::specify;
using ccspec::expect;
using ccspec::matchers::eq;

int main() {
    auto example_group = describe("Integer", [] {
        before("each", [] {
            cout << "top level before hook" << endl;
        });

        context("when positive", [] {
            before("each", [] {
                cout << "before each positive example" << endl;;
            });

            example("1 + 1 = 2", [] {
                expect(1 + 1).to(eq(2));
            });

            it("has a positive product with itself", [] {
                expect((42) * (42) > 0).to(eq(true));
            });
        });

        context("when negative", [] {
            before("each", [] {
                cout << "before each negative example" << endl;
            });

            specify("the product with its positive self is negative", [] {
                expect((-42) * 42 < 0).to(eq(true));
            });
        });
    });

    example_group->run();

    delete example_group;

    return 0;
}
