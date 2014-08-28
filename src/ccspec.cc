#include <ccspec.h>

using ccspec::expect;
using ccspec::eq;

int main() {
    expect(1).to(eq(1.01));

    return 0;
}
