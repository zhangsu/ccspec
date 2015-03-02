#include <iostream>
#include <ccspec.h>

using std::cout;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::ExampleGroup;
using ccspec::core::Reporter;

namespace spec {
namespace matchers {

extern ExampleGroup* eq_spec;

} // namespace matchers
} // namespace spec

int main() {
    using namespace spec;

    DocumentationFormatter formatter(cout);
    Reporter reporter(&formatter);

    bool succeeded = matchers::eq_spec->run(reporter);

    delete matchers::eq_spec;

    return !succeeded;
}
