#!/bin/bash

LOG_FILE="test_results.txt"

> $LOG_FILE

# Создаем тестовые файлы с массивами
echo "5" > mas1.txt
echo "10.5 -5.2 3.7 15.1 -8.9" >> mas1.txt

echo "4" > mas2.txt
echo "2.0 4.5 6.1 8.3" >> mas2.txt

echo "6" > mas3.txt
echo "1.1 2.2 3.3 4.4 5.5 6.6" >> mas3.txt

# Создаем входные данные для тестов
echo "3.0" > input1.txt
echo "8.0" >> input1.txt

echo "0.0" > input2.txt
echo "20.0" >> input2.txt

echo "100.0" > input3.txt
echo "200.0" >> input3.txt

echo "abc" > invalid_input1.txt
echo "30.0" >> invalid_input1.txt

echo "10.0" > invalid_input2.txt
echo "xyz" >> invalid_input2.txt

echo "50.0" > reverse_range.txt
echo "20.0" >> reverse_range.txt

print_file_contents() {
    echo "Содержимое файлов массивов:" | tee -a $LOG_FILE
    echo "mas1.txt: $(cat mas1.txt)" | tee -a $LOG_FILE
    echo "mas2.txt: $(cat mas2.txt)" | tee -a $LOG_FILE
    echo "mas3.txt: $(cat mas3.txt)" | tee -a $LOG_FILE
    echo | tee -a $LOG_FILE
}

test_program() {
    local program_name=$1
    local test_name=$2
    local input_file=$3
    
    echo "==================================================" | tee -a $LOG_FILE
    echo "ПРОГРАММА: $program_name" | tee -a $LOG_FILE
    echo "ТЕСТ: $test_name" | tee -a $LOG_FILE
    echo "==================================================" | tee -a $LOG_FILE
    echo | tee -a $LOG_FILE
    echo "ВХОДНЫЕ ДАННЫЕ:" | tee -a $LOG_FILE
    echo "Диапазон: $(cat $input_file | tr '\n' ' ')" | tee -a $LOG_FILE
    print_file_contents
    echo "РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ:" | tee -a $LOG_FILE
    echo "------------------------------------------" | tee -a $LOG_FILE
    ./$program_name < $input_file mas1.txt mas2.txt mas3.txt output.txt 2>&1 | tee -a $LOG_FILE
    echo "------------------------------------------" | tee -a $LOG_FILE
    
    # Показываем содержимое выходного файла если он создан
    if [ -f "output.txt" ]; then
        echo "Содержимое output.txt:" | tee -a $LOG_FILE
        cat output.txt | tee -a $LOG_FILE
        rm -f output.txt
    fi
    echo | tee -a $LOG_FILE
    echo | tee -a $LOG_FILE
}

# Компилируем программу если нужно
if [ ! -f "program" ]; then
    echo "Компиляция программы..." | tee -a $LOG_FILE
    g++ -o program main.cpp 2>&1 | tee -a $LOG_FILE
    if [ ${PIPESTATUS[0]} -ne 0 ]; then
        echo "Ошибка компиляции!" | tee -a $LOG_FILE
        exit 1
    fi
fi

echo "НАЧАЛО ТЕСТИРОВАНИЯ" | tee -a $LOG_FILE
echo "==================================================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

test_program "program" "Нормальные данные (диапазон 3.0-8.0)" "input1.txt"

test_program "program" "Широкий диапазон 0.0-20.0 (все элементы)" "input2.txt"

test_program "program" "Диапазон 100.0-200.0 (нет элементов)" "input3.txt"

test_program "program" "Обратный диапазон (50.0-20.0)" "reverse_range.txt"

echo "==================================================" | tee -a $LOG_FILE
echo "ПРОГРАММА: program" | tee -a $LOG_FILE
echo "ТЕСТ: Недостаточно параметров" | tee -a $LOG_FILE
echo "==================================================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE
echo "ВХОДНЫЕ ДАННЫЕ:" | tee -a $LOG_FILE
echo "Диапазон: $(cat input1.txt | tr '\n' ' ')" | tee -a $LOG_FILE
print_file_contents
echo "РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ:" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < input1.txt mas1.txt mas2.txt 2>&1 | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

test_program "program" "Нечисловой ввод начала диапазона" "invalid_input1.txt"

test_program "program" "Нечисловой ввод конца диапазона" "invalid_input2.txt"

# Очистка
rm -f input1.txt input2.txt input3.txt
rm -f invalid_input1.txt invalid_input2.txt reverse_range.txt
rm -f mas1.txt mas2.txt mas3.txt

echo "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" | tee -a $LOG_FILE