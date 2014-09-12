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
        before("all", [] {
            cout << "outer before all hook" << endl;
        });

        before("each", [] {
            cout << "outer before each hook" << endl;
        });

        context("when positive", [] {
            before("context", [] {
                cout << "inner before all hook" << endl;
            });

            before("example", [] {
                cout << "inner before each hook" << endl;;
            });

            example("1 + 1 = 2", [] {
                cout << "exmaple" << endl;
                expect(1 + 1).to(eq(2));
            });

            it("has a positive product with itself", [] {
                cout << "exmaple" << endl;
                expect((42) * (42) > 0).to(eq(true));
            });
        });

        context("when negative", [] {
            before("each", [] {
                cout << "inner before each hook" << endl;
            });

            specify("the product with its positive self is negative", [] {
                cout << "exmaple" << endl;
                expect((-42) * 42 < 0).to(eq(true));
            });
        });
    });

    example_group->run();

    delete example_group;

    return 0;
}
