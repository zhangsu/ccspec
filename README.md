# CCSpec [![Build Status](https://travis-ci.org/zhangsu/ccspec.svg?branch=master)](https://travis-ci.org/zhangsu/ccspec)

```c++
describe("CCSpec", [] {
```

CCSpec is a BDD-style testing framework for C++, specifially, C++11. You write
tests (or specs in CCSpec context) using a semi-natural language that is
perfectly valid C++ code, effectively making your specs executable
documentation. Ideally, reading the spec code as well as the documentation
output out loud should just sound like speaking English.

CCSpec is derived from RSpec, the BDD testing framework for Ruby. In fact,
CCSpec is simply an attempt to port RSpec from Ruby to C++ as much as possible.

```c++
});
```

## Getting Started
CCSpec contains hierarchical structures of example groups and examples. Each
example group is a collection of descriptions of related behavioral examples.
The `describe` function returns an example group, which can contain multiple
examples specified by the `example`, `specify` or `it`.

```c++
describe("elementary school arithmetics", [] {
  example("one plus one equals two", [] {
    expect(1 + 1).to(eq(2));
  });

  specify("three minus four is less than or equal to zero", [] {
    expect(3 - 4).to(be <= 0);
  });
});
```

In case of describing an object, it is more natural to start the description
with the subject "it". It just reads better.

```c++
class Student {
 public:
  bool hasPapers() const {
    return true;
  }

  string status() const {
    return "alumni";
  }
};

describe("Student", [] {
  Student subject;

  it("has published papers", [subject] {
    expect(subject.hasPapers()).to(be_truthy);
  });

  it("is alumni", [subject] {
    expect(subject.status()).to(eq("alumni"));
  });
});
```

`example`, `specify` and `it` are all synonymous. They are used in different
contexts to make the specs more readable.

## Try it out
```
git clone git@github.com:zhangsu/ccspec.git
cd ccspec
cd build && cmake .. && make && spec/ccspec_spec
```
