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
CCSpec contains hierarchical structures of *example group*s and *example*s. Each
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

It's also possible to do initialization and cleanup before each test case
similar to the magical 'setup' and 'teardown' functions in traditional unit
testing frameworks. In CCSpec, these are known as *before each* and *after
each* hooks.

```c++
describe("Duck", [] {
  shared_ptr<Duck> duck = std::make_shared<Duck>();
  
  before("each", [duck]() mutable {
    duck.reset(new Duck());
  });
  
  after("each", [] {
    // Do some finalization after each example.
  });

  it("quacks", [duck] {
    expect(duck->respondTo('quack')).to(be_truthy);
  });
});
```

Example groups can be nested as deep as needed. Before and after hooks can also
be used in the nested example groups to only apply to the immediate enclosing
example group:

```c++
class Student {
 public:
  void setName(string name) {
    this->name = name;
  }

  void setMark(int mark) {
    this->mark = mark;
  }

  string getEvaluation() const {
    if (mark > 90) {
      return name + " is superb!";
    } else if (mark > 80) {
      return name + " is excellent!";
    } else if (mark > 70) {
      return name + " is good!";
    } else if (mark > 60) {
      return name + " is okay.";
    } else {
      return name + " needs improvement";
    }
  }

 private:
  string name;
  int mark;
};

describe("Student", [] {
  Student* student = new Student();
  
  before("each", [student] {
    student->setName("Joe");
  });
  
  describe("with perfect mark", [student] {
    before("each", [student] {
      student->setMark(100);
    });

    it("gets superb evaluation", [student] {
      expect(student->getEvaluation()).to(contain("superb"));
    });
  });

  describe("with failing mark", [student] {
    before("each", [student] {
      student->setMark(49);
    });

    it("gets 'needs improvement' evaluation", [student] {
      expect(student->getEvaluation()).to(contain("needs improvement"));
    });
  });

  after("all", [student] {
    delete student;
  });
});
```

## Try It Out
```Bash
git clone git@github.com:zhangsu/ccspec.git
cd ccspec
cd build && cmake .. && make
```

### Run tests for CCSpec written in CCSpec!
```Bash
# In build directory
spec/ccspec_spec
```
