CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror
TARGET = program
SOURCES = dvoichnyifile.cpp modules.cpp
HEADERS = modules.h
TEXT_FILE = textmat.txt
BIN_FILE = binfile.bin

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET) $(TEXT_FILE)
	./$(TARGET) $(TEXT_FILE) $(BIN_FILE)

clean:
	rm -f $(TARGET) $(BIN_FILE)

.PHONY: clean run