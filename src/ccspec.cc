#include <iostream>
#include <ccspec.h>

using std::cout;
using std::endl;
using ccspec::core::after;
using ccspec::core::around;
using ccspec::core::before;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::formatters::ProgressFormatter;
using ccspec::core::it;
using ccspec::core::example;
using ccspec::core::specify;
using ccspec::core::Example;
using ccspec::core::Reporter;
using ccspec::expect;
using ccspec::matchers::eq;

int main() {
    auto example_group = describe("Integer", [] {
        before("all", [] {
            cout << "outer before all" << endl;
        });

        before("each", [] {
            cout << "outer before each" << endl;
        });

        around("each", [](const Example& example) {
            cout << "outer around each begin" << endl;
            example.run();
            cout << "outer around each end" << endl;
        });

        context("when positive", [] {
            before("context", [] {
                cout << "inner before all" << endl;
            });

            before("example", [] {
                cout << "inner before each" << endl;;
            });

            around("each", [](const Example& example) {
                cout << "inner around each begin" << endl;
                example.run();
                cout << "inner around each end" << endl;
            });

            example("1 + 1 = 2", [] {
                cout << "exmaple" << endl;
                expect(1 + 1).to(eq(3));
            });

            it("has a positive product with itself", [] {
                cout << "exmaple" << endl;
                expect((42) * (42) > 0).to(eq(true));
            });
        });

        context("when negative", [] {
            before("each", [] {
                cout << "inner before each" << endl;
            });

            specify("the product with its positive self is negative", [] {
                cout << "exmaple" << endl;
                expect((-42) * 42 < 0).to(eq(true));
            });
        });

        after("each", [] {
            cout << "outer after each" << endl;
        });

        after("all", [] {
            cout << "outer after all" << endl;
        });
    });

    ProgressFormatter formatter(cout);
    Reporter reporter(&formatter);
    example_group->run(reporter);

    delete example_group;

    return 0;
}
