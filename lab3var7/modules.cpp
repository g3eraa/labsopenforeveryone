#include "modules.h"
#include <fstream>
#include <iostream>
using namespace std;

using Record = short[3];
size_t rec_size = 3 * sizeof(short);

int input(int *n, short x[], char *fname);
int BinOutput(int n, short x[], char *fname);
int BinInput(short x[], int *n, char *fname);
int Swap(int n, char *fname, int record1, int record2);
int input(int *n, short x[], char *fname) {
  ifstream file(fname);
  if (!file.is_open()) {
    cout << "Невозможно открыть файл '" << fname << "'" << endl;
    return 0;
  }
  file >> *n;
  if (file.fail()) {
    cout << "Ошибка чтения из файла '" << fname << "'" << endl;
    return 0;
  }
  if (*n < 2) {
    cout << "Кол-во записей должно быть хотя бы 2" << endl;
    return 0;
  }

  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < 3; j++) {
      file >> x[i * 3 + j];
      if (file.fail()) {
        cout << "Ошибка чтения из файла '" << fname << "'" << endl;
        return 0;
      }
    }
  }
  file.close();
  return 1;
}

int BinOutput(int n, short x[], char *fname) {
  ofstream file(fname, ios_base::out | ios_base::binary);
  if (!file.is_open()) {
    cout << "Невозможно открыть файл " << fname << endl;
    return 0;
  }

  file.write(reinterpret_cast<char *>(x), n * 3 * sizeof(short));

  if (file.fail()) {
    cout << "Логическая ошибка при записи" << endl;
    file.close();
    return 0;
  }
  if (file.bad()) {
    cout << "Критическая ошибка при записи" << endl;
    file.close();
    return 0;
  }

  file.close();
  return 1;
}

int BinInput(short x[], int *n, char *fname) {
  ifstream file(fname, ios_base::in | ios_base::binary);
  if (!file.is_open()) {
    cout << "Невозможно открыть файл '" << fname << "'\n";
    return 0;
  }

  file.seekg(0, ios_base::end);
  int total_bytes = file.tellg();
  *n = total_bytes / rec_size;
  file.seekg(0, ios_base::beg);

  file.read(reinterpret_cast<char *>(x), *n * rec_size);

  if (file.fail()) {
    cout << "Ошибка чтения из файла '" << fname << "'\n";
    return 0;
  }
  file.close();
  return 1;
}
int Swap(int n, char *fname, int record1, int record2) {
  fstream file(fname, ios_base::in | ios_base::out | ios_base::binary);
  if (!file.is_open()) {
    cout << "Невозможно открыть файл '" << fname << "'\n";
    return 0;
  }

  if (record1 < 0 || record1 >= (n + 1) || record2 < 0 || record2 >= (n + 1)) {
    cout << "Неверные номера записей\n";
    return 0;
  }

  short rec1[3], rec2[3];

  file.seekg(record1 * rec_size, ios_base::beg);
  file.read(reinterpret_cast<char *>(rec1), rec_size);

  file.seekg(record2 * rec_size, ios_base::beg);
  file.read(reinterpret_cast<char *>(rec2), rec_size);

  file.seekp(record1 * rec_size, ios_base::beg);
  file.write(reinterpret_cast<char *>(rec2), rec_size);

  file.seekp(record2 * rec_size, ios_base::beg);
  file.write(reinterpret_cast<char *>(rec1), rec_size);

  if (file.fail()) {
    cout << "Ошибка при обмене записей\n";
    return 0;
  }

  file.close();
  return 1;
}
