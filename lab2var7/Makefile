# Компилятор
CC = g++
# Флаги компиляции
CFLAGS = -Wall -Wextra -Werror -std=c++11
# Имя исполняемого файла
TARGET = program
TARGET_1 = program_1
# Исходные файлы
SOURCE = matrixfull.cpp 
SOURCE_1 = matrixbezpotokov.cpp
# Объектные файлы
OBJECT = $(SOURCE: matrixfull.cpp=matrixfull.o)
OBJECT_1 = $(SOURCE_1: matrixbezpotokov.cpp=matrixbezpotokov.o)

# Файлы с данными
DATA_FILES = mat1.txt mat2.txt

# Правило по умолчанию
all: $(TARGET) $(TARGET_1)

# Сборка исполняемого файла
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECT)
$(TARGET_1): $(OBJECT_1)
	$(CC) $(CFLAGS) -o $(TARGET_1) $(OBJECT_1)

# Компиляция исходных файлов
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) $(DATA_FILES)

run_second: $(TARGET_1)
	./$(TARGET_1) $(DATA_FILES)

# Очистка
clean:
	rm -f $(TARGET) $(OBJECTS)


.PHONY: all run run_second clean 