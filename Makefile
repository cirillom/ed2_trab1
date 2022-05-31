
RM     = rm -f
MKDIR  = mkdir -p
7ZA    = 7za
CC    ?= gcc

BUILDD ?= build
SRCD   ?= src

PROGNAME   ?= main
EXECUTABLE ?= $(BUILDD)/$(PROGNAME)
ZIPFILE    ?= ../zipfile.zip
CFILES      = $(wildcard $(SRCD)/*.c)
OFILES      = $(patsubst %.c,%.o, $(CFILES))


CFLAGS += -Wall -Wextra -Wpedantic


.PHONY: all clean zip run debug

all: $(EXECUTABLE)

clean:
	@$(RM) $(OFILES)
	@$(RM) $(ZIPFILE)
	@$(RM) -r $(BUILDD)

zip: clean
	$(7ZA) a $(ZIPFILE) ./*

run: $(EXECUTABLE)
	@./$(EXECUTABLE) $(ARGS)

debug: CFLAGS+=-g -O0
debug: clean
debug: $(EXECUTABLE)


$(EXECUTABLE): $(OFILES)
	@$(MKDIR) $(BUILDD)
	$(CC) $(LDFLAGS) $(OFILES) -o $(EXECUTABLE)
