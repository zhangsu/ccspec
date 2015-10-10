#include <iostream>

#include "ccspec/core.h"

using std::cout;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::ExampleGroup;
using ccspec::core::Reporter;

namespace spec {
namespace expectation {

extern ExampleGroup* mismatch_spec;
extern ExampleGroup* unexpected_match_spec;

}  // namespace expectation

namespace matchers {

extern ExampleGroup* be_compared_to_spec;
extern ExampleGroup* be_falsey_spec;
extern ExampleGroup* be_something_spec;
extern ExampleGroup* be_spec;
extern ExampleGroup* be_truthy_spec;
extern ExampleGroup* contain_spec;
extern ExampleGroup* eq_spec;
extern ExampleGroup* match_spec;

}  // namespace matchers

namespace support {

extern ExampleGroup* exception_spec;
extern ExampleGroup* inspect_spec;

}  // namespace support
}  // namespace spec

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);

  ExampleGroup* example_groups[] = {
    spec::expectation::mismatch_spec,
    spec::expectation::unexpected_match_spec,
    spec::matchers::be_compared_to_spec,
    spec::matchers::be_falsey_spec,
    spec::matchers::be_something_spec,
    spec::matchers::be_spec,
    spec::matchers::be_truthy_spec,
    spec::matchers::contain_spec,
    spec::matchers::eq_spec,
    spec::matchers::match_spec,
    spec::support::exception_spec,
    spec::support::inspect_spec,
  };
  bool succeeded = true;
  for (auto example_group : example_groups) {
    succeeded = example_group->run(reporter) && succeeded;
    delete example_group;
  }

  return !succeeded;
}
