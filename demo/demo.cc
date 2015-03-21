#include <iostream>

#include "ccspec.h"

using std::cout;
using std::endl;
using ccspec::core::after;
using ccspec::core::around;
using ccspec::core::before;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::formatters::ProgressFormatter;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::it;
using ccspec::core::example;
using ccspec::core::specify;
using ccspec::core::Example;
using ccspec::core::Reporter;
using ccspec::expect;
using ccspec::matchers::be;
using ccspec::matchers::eq;

int main() {
  auto example_group = describe("Integer", [] {
    before("all", [] {
    });

    before("each", [] {
    });

    around("each", [](const Example& example) {
      example.run();
    });

    context("when positive", [] {
      before("context", [] {
      });

      before("example", [] {
      });

      around("each", [](const Example& example) {
        example.run();
      });

      example("1 + 1 = 2", [] {
        expect(1 + 1).to(be == 2);
      });

      it("has a positive product with itself", [] {
        expect((42) * (42)).to(be > 0);
      });
    });

    context("when negative", [] {
      before("each", [] {
      });

      specify("the product with its positive self is negative", [] {
        expect((-42) * 42).to(be < 0);
      });
    });

    after("each", [] {
    });

    after("all", [] {
    });
  });

  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);
  example_group->run(reporter);

  delete example_group;

  return 0;
}
