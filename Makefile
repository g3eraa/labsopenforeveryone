# Компилятор
CC = g++
# Флаги компиляции
CFLAGS = -Wall -Wextra -Werror -std=c++11
# Имя исполняемого файла
TARGET = program
# Исходные файлы
SOURCES = streammassive.cpp
# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Файлы с данными
DATA_FILES = mas1.txt mas2.txt mas3.txt

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Компиляция исходных файлов
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Запуск программы
run: $(TARGET)
	./$(TARGET) $(DATA_FILES)

# Очистка
clean:
	rm -f $(TARGET) $(OBJECTS)

# Показать содержимое тестовых файлов
show_data:
	@echo "Содержимое mas1.txt:"
	@cat mas1.txt || echo "Файл не существует"
	@echo -e "\nСодержимое mas2.txt:"
	@cat mas2.txt || echo "Файл не существует"
	@echo -e "\nСодержимое mas3.txt:"
	@cat mas3.txt || echo "Файл не существует"

.PHONY: all run clean show_data