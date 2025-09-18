CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
TARGET = program_bez_potokami
SOURCES = main_2.cpp
OBJECTS = $(SOURCES: .cpp= .o)
DATA_FILES = f1.txt
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
$.o: $.cpp
	$(CC) $(CFLAGS) -c $c -o $@
run: $(TARGET)
	./$(TARGET) $(DATA_FILES)
clean: 
	rm -f $(TARGET) $(OBJECTS)
.PHONY: all run clean