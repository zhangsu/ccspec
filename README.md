# CCSpec [![Build Status](https://travis-ci.org/zhangsu/ccspec.svg?branch=master)](https://travis-ci.org/zhangsu/ccspec) [![Biicode](https://webapi.biicode.com/v1/badges/zhangsu/zhangsu/ccspec/master)](https://www.biicode.com/zhangsu/ccspec)

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

There are two ways to link the CCSpec library to your test executable(s):
the Biicode way or the regular CMake way.

### Automatic linkage with Biicode

The easiest way to use CCSpec in your project is by using
[Biicode](https://www.biicode.com). Biicode is a C and C++ dependency manager,
resembling RubyGems for Ruby and NPM for Node.js.

If your project already uses Biicode, great! You can skip to the
[Configure Biicode](#configure-biicode)
section.

#### Download and install Biicode

You can follow the official instructions at Biicode's
[installation page](http://docs.biicode.com/c++/installation.html).

Alternatively, you can install Biicode through your native package manager if
Biicode is in the repositories. For example, Arch Linux users maintain a Biicode
package in the [AUR](https://aur.archlinux.org/packages/biicode/). For OS X
users, Homebrew Cask also has an
[entry](https://github.com/caskroom/homebrew-cask/blob/master/Casks/biicode.rb).

#### Adapt your project as a Biicode project

Take a look at Biicode's
[Adapt your library guide](http://docs.biicode.com/c++/adapt_library_guide.html)
for how to use Biicode for your existing project.

```Zsh
cd <your_project_root_directory>
bii init -L
```

#### Configure Biicode

Add the following config to your `biicode.conf` under the root directory of your
project:

```
[requirements]
  zhangsu/ccspec: 0

[includes]
  ccspec/*.h: zhangsu/ccspec/include/
```

the [requirements] section declares to have your project depend on
 `zhangsu/ccspec`, which is the
[official published Biicode block for CCSpec](https://www.biicode.com/zhangsu/ccspec).
The number `0` indicates which CCSpec version to use, and currently there is only
the development version which is `0`. The [includes] section defines a short form
for the include path so that, instead of using the fully-qualified Biicode path:

```C++
#include "zhangsu/ccspec/include/ccspec/*.h"
```

You can just do

```C++
#include "ccspec/*.h"
```

Note that you may still need
[other config sections](http://docs.biicode.com/c++/reference/biicode-conf.html)
in your biicode.conf for your project, but the above two are crucial for using
CCSpec. Most likely you will need a
[\[tests\]](http://docs.biicode.com/c++/reference/biicode-conf.html#tests) section
to specify the CCSpec spec files of your project so that they are not linked to
your project's production libraries or executables:

```
[tests]
  spec/*
```

This specifies that files under the `spec/` directory are test files. To test this,
put a simple spec file under the `spec/` directory:

```C++
#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using std::cout;
using std::ostringstream;
using ccspec::core::Reporter;
using ccspec::core::describe;
using ccspec::core::example;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::matchers::eq;
using ccspec::expect;

auto addition_spec = describe("Addition", [] {
  example("1 + 1 = 2", [] {
    expect(1 + 1).to(eq(2));
  });
});

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);
  bool succeeded = addition_spec->run(reporter);
  delete addition_spec;
  return !succeeded;
}
```

At this point, you should be able to run `bii find` to download all the dependencies
including CCSpec.

##### CMake
In your main Biicode CMake file, add

```CMake
IF(APPLE)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF(APPLE)
```
before your `ADD_BII_TARGETS()` call. This is to turn on C++11 support so that
CCSpec header can actually be compiled.

Then, to test if everything works:
```Zsh
bii build # build your main libraries and executables
bii test  # run your CCSpec specs
```

#### Example project
Here's an [example project](https://github.com/zhangsu/ccspec-example/) that uses
CCSpec to test a simple binary search tree, using Biicode to manage the dependency.

### Linkage with CMake
CCSpec can also be compiled from source and linked to your project through
regular CMake workflow.
```Zsh
git clone git@github.com:zhangsu/ccspec.git
cd ccspec
cd build
cmake ..
make
```
Then a shared library will be generated under `build/src/`. For example, on Linux
`libccspec.so` is generated. On OS X `libccspec.dylib` is generated. Headers are
under `include/`.

You may also choose to install the headers and library file to your system directory
by running `make install`.

## Detailed Usage

CCSpec contains hierarchical structures of *example group*s and *example*s. Each
example group is a collection of descriptions of related behavioral examples.
The `describe` function returns an example group, which can contain multiple
examples specified by the `example`, `specify` or `it`.

```c++
auto arithmetics_spec = describe("elementary school arithmetics", [] {
  example("one plus one equals two", [] {
    expect(1 + 1).to(eq(2));
  });

  specify("three minus four is less than or equal to zero", [] {
    expect(3 - 4).to(be <= 0);
  });
});
```
Note that the above root example group is saved in a global variable
`arithmetics_spec`, which can be referenced later in the `main` function to
be actually executed. You can also write example groups in a function scope, but
then everything needs to be indented by one more level so its less
width-efficient.

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
Duck* duck;

auto duck_spec = describe("Duck", [] {
  before("each", [] {
    duck = new Duck();
  });
  
  after("each", [] {
    delete duck;
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

auto student_spec = describe("Student", [] {
  Student* student = new Student();
  
  before("all", [student] {
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

Note that the above snippet introduces another kind of before and after hook --
*before all* hook and *after all* hook. Before all hook is executed before
executing all examples and before each hooks in the enclosing example group.
After all hook is executed after all examples and after each hooks in the
enclosing example group.

## Run tests for CCSpec written in CCSpec!
```Zsh
git clone git@github.com:zhangsu/ccspec.git
cd ccspec
cd build
cmake ..
make
spec/ccspec_spec
```
