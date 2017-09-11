CC    ?= gcc
CXX   ?= g++

EXE = main

CDEBUG = -g -Wall

CXXDEBUG = -g -Wall

CSTD = -std=c99
CXXSTD = -std=c++11

CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)


CPPOBJ = src/main src/f_driver
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))

OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST = $(addsuffix .o, $(OBJ)) $(OBJS) \
			parser.tab.c parser.tab.h \
			location.hh position.hh \
			stack.hh parser.output parser.o \
			lexer.o lexer.yy.cc $(EXE)\

.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)


parser: parser.y
	bison -d -v parser.y
	$(CXX) $(CXXFLAGS) -c -o parser.o parser.tab.c

lexer: scanner.l
	flex --outfile=lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c lexer.yy.cc -o lexer.o

.PHONY: test
test:
	cd test && ./swap.f

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)