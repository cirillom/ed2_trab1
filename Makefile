
CC ?= gcc
CFLAGS += -Wall -Wextra -Wpedantic

EXECUTABLE ?= build/main
TEST_CFILES = $(wildcard src/*_teste.c)
TEST_OFILES = $(patsubst src/%_teste.c, build/%_teste.o, $(TEST_CFILES))
TEST_BINS   = $(patsubst src/%_teste.c, build/%, $(TEST_CFILES))

ZIPFILE    ?= ../zipfile.zip
CFILES      = $(filter-out %_teste.c, $(wildcard src/*.c))
OFILES      = $(patsubst src/%.c,build/%.o, $(CFILES))


.PHONY: all clean zip run test debug

all: $(EXECUTABLE)

clean:
	@rm -f $(ZIPFILE)
	@rm -rf build/

zip: clean
	7za a $(ZIPFILE) ./*

run: $(EXECUTABLE)
	@./$(EXECUTABLE) $(ARGS)

test: $(TEST_BINS)

debug: CFLAGS+=-g -O0
debug: clean
debug: $(EXECUTABLE) test


$(EXECUTABLE): $(OFILES)
	@mkdir -p build
	$(CC) $(LDFLAGS) -o $@ $^


build/%: $(filter-out build/main.o, $(OFILES)) build/%_teste.o
	@mkdir -p build
	$(CC) $(LDFLAGS) -o $@ $^	


build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c -o $@ $^

valgrind: $(EXECUTABLE)
	cd $(BUILDD) && valgrind $(VDFLAGS) ./$(PROGNAME)