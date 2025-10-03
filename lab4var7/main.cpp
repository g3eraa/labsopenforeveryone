#include <iostream>
#include "modules.h"
using namespace std;
int main() {
    char input[NMAX];
    char result[NMAX];
    
    cout << "Введите строку: ";
    inputString(input);
    
    bool isEmpty = true;
    for (const char* p = input; *p; p++) {
        if (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\r') {
            isEmpty = false;
            break;
        }
    }
    
    if (isEmpty) {
        cout << "Введена пустая строка!" << endl;
        result[0] = '\0';
    } else {
        sortWordsByLength(input, result);
        
        bool hasWords = false;
        for (const char* p = result; *p; p++) {
            if (isWordChar(*p)) {
                hasWords = true;
                break;
            }
        }
        
        if (!hasWords) {
            cout << "Строка не содержит слов!" << endl;
            result[0] = '\0';
        } else {
            cout << "Результат: " << result << endl;
        }
    }
    
    return 0;
}