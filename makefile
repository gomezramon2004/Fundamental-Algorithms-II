CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
LNKDIR = linkedList
PRSDIR = parse
SRTDIR = sort
SRCDIR = search
PRNDIR = print

SRCS = main.cpp \
		$(LNKDIR)/linkedList.cpp \
        $(PRSDIR)/parse.cpp \
		$(PRNDIR)/print.cpp \
        $(SRTDIR)/mergeSort.cpp \
		$(SRCDIR)/binarySearch.cpp \

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean