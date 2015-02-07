CC                = g++
LINKER            = g++
FLAGS             = -Wall -Wextra
CFLAGS            = $(FLAGS) -std=c++11 -c -Iinclude -fPIC
LFLAGS            = $(FLAGS)
LIBLFLAGS         = $(LFLAGS) -shared
UTILLFLAGS        = $(LFLAGS) -Llib -lccspec
SRCDIR            = src/
SRCCOREDIR        = $(SRCDIR)core/
SRCEXPECTATIONDIR = $(SRCDIR)expectation/
SRCMATCHERSDIR    = $(SRCDIR)matchers/
SRCSUPPORTDIR     = $(SRCDIR)support/
BINDIR            = bin/
LIBDIR            = lib/
OUTPUTS           = $(CCSPECOUTPUT) $(UTILOUTPUT)
UTILOUTPUT        = $(BINDIR)ccspec
CCSPECOUTPUT      = $(LIBDIR)libccspec.so
CCSPECOBJECTS     = \
  $(addprefix $(SRCCOREDIR), example.o example_group.o execution_result.o\
                             formatter.o hooks.o reporter.o unexpected_throw.o)\
  $(addprefix $(SRCCOREDIR)formatters/, documentation_formatter.o\
                                        progress_formatter.o text_formatter.o)\
  $(addprefix $(SRCEXPECTATIONDIR), )\
  $(addprefix $(SRCMATCHERSDIR), be_something.o be_truthy.o)\
  $(addprefix $(SRCSUPPORTDIR), exception.o inspect.o)
UTILOBJECTS = $(SRCDIR)ccspec.o

ifeq ($(DEBUG),1)
  FLAGS += -g
else
  FLAGS += -O3
  CFLAGS += -DNDEBUG
endif

.PHONY: clean

all: $(OUTPUTS)

$(UTILOUTPUT): $(UTILOBJECTS) $(CCSPECOUTPUT) bin/
	$(LINKER) $(UTILOBJECTS) $(UTILLFLAGS) -o $@

$(CCSPECOUTPUT): $(CCSPECOBJECTS) lib/
	$(LINKER) $(CCSPECOBJECTS) $(LIBLFLAGS) -o $@

bin/:
	mkdir -p bin

lib/:
	mkdir -p lib

-include $(CCSPECOBJECTS:.o=.d)

%.o: %.cc
	$(CC) -c -MMD $(CFLAGS) $< -o $@

clean:
	find . -name '*.o' -o -name '*.d' | xargs rm -f
	rm -rf {bin,lib}
