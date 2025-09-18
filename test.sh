#!/bin/bash

LOG_FILE="test_results.txt"

echo "==================================================" | tee -a $LOG_FILE
echo "ТЕСТИРОВАНИЕ С ФАЙЛАМИ mas1.txt, mas2.txt, mas3.txt" | tee -a $LOG_FILE
echo "==================================================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# Проверяем существование файлов
if [ ! -f "mas1.txt" ]; then
    echo "ОШИБКА: Файл mas1.txt не найден!" | tee -a $LOG_FILE
    exit 1
fi

if [ ! -f "mas2.txt" ]; then
    echo "ОШИБКА: Файл mas2.txt не найден!" | tee -a $LOG_FILE
    exit 1
fi

if [ ! -f "mas3.txt" ]; then
    echo "ОШИБКА: Файл mas3.txt не найден!" | tee -a $LOG_FILE
    exit 1
fi

# Создаем файлы с входными данными
echo "10" > input1.txt
echo "30" >> input1.txt

echo "0" > input2.txt
echo "100" >> input2.txt

echo "100" > input3.txt
echo "200" >> input3.txt

echo "abc" > invalid_input1.txt
echo "30" >> invalid_input1.txt

echo "10" > invalid_input2.txt
echo "xyz" >> invalid_input2.txt

echo "50" > reverse_range.txt
echo "20" >> reverse_range.txt

# Очищаем лог-файл перед началом тестирования
> $LOG_FILE

# ===== ТЕСТ 1: Нормальная работа =====
echo "ТЕСТ 1: Нормальные данные (диапазон 10-30)" | tee -a $LOG_FILE
echo "Используются: mas1.txt, mas2.txt, mas3.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < input1.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE
echo

# ===== ТЕСТ 2: Все элементы в диапазоне =====
echo "ТЕСТ 2: Диапазон 0-100 (все элементы)" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < input2.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

echo

# ===== ТЕСТ 3: Нет элементов в диапазоне =====
echo "ТЕСТ 3: Диапазон 100-200 (нет элементов)" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < input3.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

echo

# ===== ТЕСТ 4: Обратный диапазон =====
echo "ТЕСТ 4: Обратный диапазон (50-20)" | tee -a $LOG_FILE
echo "Ожидается: автоматическая корректировка" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < reverse_range.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

echo

# ===== ТЕСТ 5: Недостаточно параметров =====
echo "ТЕСТ 5: Недостаточно параметров" | tee -a $LOG_FILE
echo "Ожидается: сообщение об ошибке" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < input1.txt mas1.txt mas2.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

echo

# ===== ТЕСТ 6: Неверный ввод диапазона =====
echo "ТЕСТ 6: Нечисловой ввод начала диапазона" | tee -a $LOG_FILE
echo "Ожидается: ошибка ввода" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < invalid_input1.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

echo

# ===== ТЕСТ 7: Неверный ввод диапазона =====
echo "ТЕСТ 7: Нечисловой ввод конца диапазона" | tee -a $LOG_FILE
echo "Ожидается: ошибка ввода" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program < invalid_input2.txt mas1.txt mas2.txt mas3.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE


rm -f input1.txt input2.txt input3.txt
rm -f invalid_input1.txt invalid_input2.txt reverse_range.txt

echo "Тестирование завершено" | tee -a $LOG_FILE
















