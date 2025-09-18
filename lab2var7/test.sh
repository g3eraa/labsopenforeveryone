#!/bin/bash

LOG_FILE="test_results.txt"
> $LOG_FILE

echo "==================================================" | tee -a $LOG_FILE
echo "ТЕСТИРОВАНИЕ ПРОГРАММ ДЛЯ РАБОТЫ С МАТРИЦАМИ" | tee -a $LOG_FILE
echo "==================================================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE


# Нормальные матрицы
echo "3 3" > mat1_normal.txt
echo "1 2 3" >> mat1_normal.txt
echo "4 0 6" >> mat1_normal.txt
echo "7 8 9" >> mat1_normal.txt

echo "2 2" > mat2_normal.txt
echo "-1 2" >> mat2_normal.txt
echo "3 4" >> mat2_normal.txt

# Матрица без нулей
echo "2 2" > mat_no_zeros.txt
echo "1 2" >> mat_no_zeros.txt
echo "3 4" >> mat_no_zeros.txt

# Матрица с отрицательными
echo "2 2" > mat_negative.txt
echo "-1 -2" >> mat_negative.txt
echo "3 4" >> mat_negative.txt

# Неправильный формат файла
echo "abc def" > mat_bad_format.txt
echo "1 2 3" >> mat_bad_format.txt

# Слишком большая матрица
echo "101 101" > mat_too_big.txt
for i in {1..101}; do
    for j in {1..101}; do
        echo -n "1 " >> mat_too_big.txt
    done
    echo "" >> mat_too_big.txt
done

# Пустой файл
touch mat_empty.txt

# Файл только с размерами
echo "2 2" > mat_only_sizes.txt

# Файл с недостаточным количеством элементов
echo "2 2" > mat_missing_elements.txt
echo "1 2" >> mat_missing_elements.txt

echo "Тестовые файлы созданы успешно" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ===== ТЕСТЫ ДЛЯ PROGRAM =====
echo "=================== PROGRAM ===================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 1: Нормальные матрицы с нулями и отрицательными
echo "ТЕСТ 1: Нормальные матрицы с нулями и отрицательными" | tee -a $LOG_FILE
echo "Файлы: mat1_normal.txt, mat2_normal.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program mat1_normal.txt mat2_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 2: Матрицы без нулей
echo "ТЕСТ 2: Матрицы без нулей" | tee -a $LOG_FILE
echo "Файлы: mat_no_zeros.txt, mat_no_zeros.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_no_zeros.txt mat_no_zeros.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 3: Матрицы с отрицательными элементами
echo "ТЕСТ 3: Матрицы с отрицательными элементами" | tee -a $LOG_FILE
echo "Файлы: mat_negative.txt, mat_negative.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_negative.txt mat_negative.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 4: Недостаточно параметров
echo "ТЕСТ 4: Недостаточно параметров" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 5: Несуществующий файл
echo "ТЕСТ 5: Несуществующий файл" | tee -a $LOG_FILE
echo "Файлы: nonexistent.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program nonexistent.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 6: Неправильный формат файла
echo "ТЕСТ 6: Неправильный формат файла" | tee -a $LOG_FILE
echo "Файлы: mat_bad_format.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_bad_format.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 7: Слишком большая матрица
echo "ТЕСТ 7: Слишком большая матрица" | tee -a $LOG_FILE
echo "Файлы: mat_too_big.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_too_big.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 8: Пустой файл
echo "ТЕСТ 8: Пустой файл" | tee -a $LOG_FILE
echo "Файлы: mat_empty.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_empty.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 9: Файл только с размерами
echo "ТЕСТ 9: Файл только с размерами" | tee -a $LOG_FILE
echo "Файлы: mat_only_sizes.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_only_sizes.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 10: Недостаточно элементов
echo "ТЕСТ 10: Недостаточно элементов" | tee -a $LOG_FILE
echo "Файлы: mat_missing_elements.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_missing_elements.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 11: Оба файла невалидные
echo "ТЕСТ 11: Оба файла невалидные" | tee -a $LOG_FILE
echo "Файлы: mat_bad_format.txt, nonexistent.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program mat_bad_format.txt nonexistent.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 12: Разные комбинации
echo "ТЕСТ 12: Разные комбинации (нули + без нулей)" | tee -a $LOG_FILE
echo "Файлы: mat1_normal.txt, mat_no_zeros.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program mat1_normal.txt mat_no_zeros.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ===== ТЕСТЫ ДЛЯ PROGRAM_1 =====
echo "=================== PROGRAM_1 ===================" | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 13: Нормальные матрицы с нулями и отрицательными
echo "ТЕСТ 13: Нормальные матрицы с нулями и отрицательными" | tee -a $LOG_FILE
echo "Файлы: mat1_normal.txt, mat2_normal.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat1_normal.txt mat2_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 14: Матрицы без нулей
echo "ТЕСТ 14: Матрицы без нулей" | tee -a $LOG_FILE
echo "Файлы: mat_no_zeros.txt, mat_no_zeros.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_no_zeros.txt mat_no_zeros.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 15: Матрицы с отрицательными элементами
echo "ТЕСТ 15: Матрицы с отрицательными элементами" | tee -a $LOG_FILE
echo "Файлы: mat_negative.txt, mat_negative.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_negative.txt mat_negative.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 16: Недостаточно параметров
echo "ТЕСТ 16: Недостаточно параметров" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 17: Несуществующий файл
echo "ТЕСТ 17: Несуществующий файл" | tee -a $LOG_FILE
echo "Файлы: nonexistent.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 nonexistent.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 18: Неправильный формат файла
echo "ТЕСТ 18: Неправильный формат файла" | tee -a $LOG_FILE
echo "Файлы: mat_bad_format.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_bad_format.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 19: Слишком большая матрица
echo "ТЕСТ 19: Слишком большая матрица" | tee -a $LOG_FILE
echo "Файлы: mat_too_big.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_too_big.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 20: Пустой файл
echo "ТЕСТ 20: Пустой файл" | tee -a $LOG_FILE
echo "Файлы: mat_empty.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_empty.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 21: Файл только с размерами
echo "ТЕСТ 21: Файл только с размерами" | tee -a $LOG_FILE
echo "Файлы: mat_only_sizes.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_only_sizes.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 22: Недостаточно элементов
echo "ТЕСТ 22: Недостаточно элементов" | tee -a $LOG_FILE
echo "Файлы: mat_missing_elements.txt, mat1_normal.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_missing_elements.txt mat1_normal.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 23: Оба файла невалидные
echo "ТЕСТ 23: Оба файла невалидные" | tee -a $LOG_FILE
echo "Файлы: mat_bad_format.txt, nonexistent.txt" | tee -a $LOG_FILE

echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat_bad_format.txt nonexistent.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE

# ТЕСТ 24: Разные комбинации
echo "ТЕСТ 24: Разные комбинации (нули + без нулей)" | tee -a $LOG_FILE
echo "Файлы: mat1_normal.txt, mat_no_zeros.txt" | tee -a $LOG_FILE
echo "------------------------------------------" | tee -a $LOG_FILE
./program_1 mat1_normal.txt mat_no_zeros.txt | tee -a $LOG_FILE
echo | tee -a $LOG_FILE


rm -f mat1_normal.txt mat2_normal.txt mat_no_zeros.txt mat_negative.txt
rm -f mat_bad_format.txt mat_too_big.txt mat_empty.txt
rm -f mat_only_sizes.txt mat_missing_elements.txt

echo "==================================================" | tee -a $LOG_FILE
