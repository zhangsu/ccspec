CC                = g++
LINKER            = g++
FLAGS             = -Wall -Wextra
CFLAGS            = $(FLAGS) -std=c++11 -c -Iinclude
LFLAGS            = $(FLAGS)
SRCDIR            = src/
SRCCOREDIR        = $(SRCDIR)core/
SRCEXPECTATIONDIR = $(SRCDIR)expectation/
SRCSUPPORTDIR     = $(SRCDIR)support/
BINDIR            = bin/
OUTPUTS           = $(CCSPECOUTPUT)
CCSPECOUTPUT      = $(BINDIR)ccspec
CCSPECOBJECTS     = $(SRCDIR)ccspec.o\
  $(addprefix $(SRCCOREDIR), example.o example_group.o execution_result.o\
                             formatter.o hooks.o reporter.o unexpected_throw.o)\
  $(addprefix $(SRCCOREDIR)formatters/, progress_formatter.o text_formatter.o)\
  $(addprefix $(SRCEXPECTATIONDIR), )\
  $(addprefix $(SRCSUPPORTDIR), exception.o)

ifeq ($(DEBUG),1)
  FLAGS += -g
else
  FLAGS += -O3
  CFLAGS += -DNDEBUG
endif

.PHONY: clean

all: $(OUTPUTS)

$(CCSPECOUTPUT): $(CCSPECOBJECTS) bin/
	$(LINKER) $(LFLAGS) $(CCSPECOBJECTS) -o $@

bin/:
	mkdir -p bin

-include $(CCSPECOBJECTS:.o=.d)

%.o: %.cc
	$(CC) -c -MMD $(CFLAGS) $< -o $@

clean:
	find . -name '*.o' -o -name '*.d' | xargs rm -f
	rm -rf {bin,lib}
