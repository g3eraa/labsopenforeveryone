#include "modules.h"
#include <fstream>
#include <iostream>
using namespace std;
const int NMAX = 1000;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cout << "Недостаточно входных параметров" << endl;
    return 1;
  }

  char *textfile = argv[1];
  char *binfile = argv[2];

  short data[NMAX * 3];
  int n = 0;
  int rec_1, rec_2;

  if (!input(&n, data, textfile)) {
    return 1;
  }

  if (!BinOutput(n, data, binfile)) {
    return 1;
  }

  short read_data[NMAX * 3];
  int records_count = 0;

  cout << "Данные до изменений:" << endl;
  if (!BinInput(read_data, &records_count, binfile)) {
    return 1;
  }
  for (int i = 0; i < records_count; i++) {
    cout << "Запись " << i + 1 << ": " << read_data[i * 3] << " "
         << read_data[i * 3 + 1] << " " << read_data[i * 3 + 2] << endl;
  }

  cout << "Введите номера записей для обмена: ";
  cin >> rec_1 >> rec_2;

  if (!Swap(n, binfile, (rec_1 - 1), (rec_2 - 1))) {
    return 1;
  }

  cout << "Данные после изменений:" << endl;
  if (!BinInput(read_data, &records_count, binfile)) {
    return 1;
  }
  for (int i = 0; i < records_count; i++) {
    cout << "Запись " << i + 1 << ": " << read_data[i * 3] << " "
         << read_data[i * 3 + 1] << " " << read_data[i * 3 + 2] << endl;
  }

  return 0;
}