#include <iostream>

#include "ccspec.h"

using std::cout;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::ExampleGroup;
using ccspec::core::Reporter;

namespace spec {
namespace matchers {

extern ExampleGroup* eq_spec;

}  // namespace matchers
}  // namespace spec

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);

  bool succeeded = spec::matchers::eq_spec->run(reporter);

  delete spec::matchers::eq_spec;

  return !succeeded;
}
