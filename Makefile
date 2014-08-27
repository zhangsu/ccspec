CC             = g++
LINKER         = g++
FLAGS          = -Wall -Wextra
CFLAGS         = $(FLAGS) -std=c++11 -c -Iinclude
LFLAGS         = $(FLAGS)
SRCDIR         = src/
OUTPUTS        = $(CCSPECOUTPUT)
CCSPECOUTPUT   = ccspec
CCSPECOBJECTS  = $(SRCDIR)ccspec.o

ifeq ($(DEBUG),1)
  FLAGS += -g
else
  FLAGS += -O3
  CFLAGS += -DNDEBUG
endif

.PHONY: clean

all: $(OUTPUTS)

$(CCSPECOUTPUT): $(CCSPECOBJECTS)
	$(LINKER) $(LFLAGS) $(CCSPECOBJECTS) -o $@

-include $(CCSPECOBJECTS:.o=.d)

%.o: %.cc
	$(CC) -c -MMD $(CFLAGS) $< -o $@

clean:
	find -name '*.o' -o -name '*.d' -o -name '$(OUTPUTS)' | xargs rm -f
