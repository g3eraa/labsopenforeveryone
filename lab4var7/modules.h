#ifndef MODULES_H
#define MODULES_H

const int NMAX = 10000;

struct Word {
    char content[100];
    int length;
};

void inputString(char* str);
bool isWordChar(char c);
void quickSort(Word* words, int left, int right);
void sortWordsByLength(const char* input, char* result);

#endif