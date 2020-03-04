#test.exe: test.cc
#	g++ -std=c++11 -I /home/liu_lab/shared/include  -L /home/liu_lab/shared#/lib/ -lCore -lMathCore test.cc -o test.exe

#############################################################################
# variables used by implicit rules to allocate ROOT headers and libs
CXXFLAGS = $(shell root-config --cflags)
LDLIBS = $(shell root-config --libs)

SRC = $(wildcard *.cc) # list all files that end with .cc
EXE = $(SRC:.cc=)      # remove .cc from those file names

all: $(EXE)
	@echo make install: copy $(EXE) to ~/bin
	@echo make clean: delete $(EXE)
	@echo make debug: check contents of Makefile variables

clean:
	$(RM) $(EXE)

install:
	mkdir -p ~/bin
	install $(EXE) ~/bin
	@echo Please add $(shell root-config --libdir)
	@echo to your LD_LIBRARY_PATH before you run any executable

debug:
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo LDLIBS = $(LDLIBS)
	@echo SRC = $(SRC)
	@echo EXE = $(EXE)

.PHONY: all clean install debug
