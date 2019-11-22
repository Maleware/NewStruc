CC = /usr/bin/gcc
CFLAGS =  -Wall -Wpedantic -Wextra -Wstrict-aliasing -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wunreachable-code

LD = /usr/bin/gcc
LDFLAGS = 

OBJDIR = obj
BINDIR = bin

SRC = $(wildcard *.c) $(wildcard ex*/*.c)
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
DEP = $(SRC:%.c=$(OBJDIR)/%.d)

all: release debug

debug: $(BINDIR)/debug/main

release: $(BINDIR)/release/main

$(BINDIR)/debug/main: $(OBJ)
	$(LD) $(LDFLAGS) $^ -g -o $@

$(BINDIR)/release/main: $(OBJ)
	$(LD) $(LDFLAGS) -O3 $^ -o $@

-include $(DEP)

$(OBJDIR)/%.o: %.c
	$(CC) -MMD $(CFLAGS) -c -o $@ $< 

print-% : ; @echo $* = $($*)

clean:
	-rm obj/*.o
	-rm obj/*/*.o
	-rm obj/*.d
	-rm obj/*/*.d
	-rm bin/*/*

.PHONY: all clean
