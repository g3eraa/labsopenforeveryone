#include <iostream>
#include <cstdio>
#include "modules.h"

void inputString(char* str) {
    fgets(str, NMAX, stdin);
    char* p = str;
    while (*p) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
}

bool isWordChar(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9');
}

void quickSort(Word* words, int left, int right) {
    if (left >= right) return;
    
    int pivot = words[(left + right) / 2].length;
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (words[i].length > pivot) i++;
        while (words[j].length < pivot) j--;
        if (i <= j) {
            Word temp = words[i];
            words[i] = words[j];
            words[j] = temp;
            i++;
            j--;
        }
    }
    
    quickSort(words, left, j);
    quickSort(words, i, right);
}

void sortWordsByLength(const char* input, char* result) {
    Word words[500];
    int wordCount = 0;
    
    const char* p = input;
    bool inWord = false;
    int currentLength = 0;
    char currentWord[100];
    
    while (*p) {
        if (isWordChar(*p)) {
            if (!inWord) {
                inWord = true;
                currentLength = 0;
            }
            if (currentLength < 99) {
                currentWord[currentLength] = *p;
                currentLength++;
            }
        } else {
            if (inWord && currentLength > 0) {
                currentWord[currentLength] = '\0';
                for (int i = 0; i <= currentLength; i++) {
                    words[wordCount].content[i] = currentWord[i];
                }
                words[wordCount].length = currentLength;
                wordCount++;
                inWord = false;
                currentLength = 0;
            }
        }
        p++;
    }
    
    if (inWord && currentLength > 0) {
        currentWord[currentLength] = '\0';
        for (int i = 0; i <= currentLength; i++) {
            words[wordCount].content[i] = currentWord[i];
        }
        words[wordCount].length = currentLength;
        wordCount++;
    }
    
    if (wordCount > 0) {
        quickSort(words, 0, wordCount - 1);
    }
    
    char* r = result;
    for (int i = 0; i < wordCount; i++) {
        const char* w = words[i].content;
        while (*w) {
            *r = *w;
            r++;
            w++;
        }
        if (i < wordCount - 1) {
            *r = ' ';
            r++;
        }
    }
    *r = '\0';
}