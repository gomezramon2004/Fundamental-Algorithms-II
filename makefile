CXX = g++
CXXFLAGS = -Wall -std=c++17 -g
TARGET = main
LNKDIR = linkedList
PRSDIR = parse
SRTDIR = sort
PRNDIR = print

SRCS = main.cpp \
		$(LNKDIR)/linkedList.cpp \
        $(PRSDIR)/parse.cpp \
        $(SRTDIR)/mergeSort.cpp \
		$(PRNDIR)/print.cpp \

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean