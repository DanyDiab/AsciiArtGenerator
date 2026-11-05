CXX ?= g++
CXXFLAGS ?= -Wall -Wextra -std=c++17
TARGET = filereader
SRC = FileReader.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
