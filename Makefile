CC = /usr/bin/gcc
CFLAGS =  -Wall -Wpedantic -Wextra -Wstrict-aliasing -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wunreachable-code -lm

LD = /usr/bin/gcc
LDFLAGS = 

OBJDIR = obj
BINDIR = bin

SRC = $(wildcard *.c) $(wildcard ex*/*.c)
OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

DRDIR = 

all: release debug

debug: CFLAGS += -g
debug: DRDIR = debug
debug: $(BINDIR)/debug/main

release: CFLAGS += -O3
release: DRDIR = release
release: $(BINDIR)/release/main

$(BINDIR)/debug/main: $(OBJ:%.o=$(OBJDIR)/debug/%.o)
	$(LD) $(LDFLAGS) $^ -o $@

$(BINDIR)/release/main: $(OBJ:%.o=$(OBJDIR)/release/%.o)
	$(LD) $(LDFLAGS) $^ -o $@

-include $(DEP: %.d=$(OBJDIR)/$(DRDIR)/%.o)

$(OBJDIR)/release/%.o: %.c
	$(CC) -MMD $(CFLAGS) -c -o $@ $< 

$(OBJDIR)/debug/%.o: %.c
	$(CC) -MMD $(CFLAGS) -c -o $@ $< 


print-% : ; @echo $* = $($*)

clean:
	-rm obj/*/*.o
	-rm obj/*/*.d
	-rm bin/*/*

.PHONY: all clean
