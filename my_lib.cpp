#include "my_lib.h"
#include <stdio.h>
#include <string.h>

bool fileExists(const char* fileName){
    FILE* f = fopen(fileName, "rb");
    if (f){
        fclose(f);
        return true;
    }
    return false;
}

long getFileLendth(const char* fileName){
    FILE* f = fopen(fileName, "rb");
    if (f){
        fseek(f, 0, SEEK_END);
        int len = ftell(f);
        fclose(f);
        return len;
    }
    return -1;
}

void insertChar(char* s, char c, int pos){
    int len = strlen(s);
    for (int i=len; i>=pos; i--){
        s[i] = s[i-1];
    }
    s[pos] = c;
}

void center(char* s, int width){
    int len = strlen(s);
    int i = 0;
    while (len < width){
        if (i%2==0){
            insertChar(s, ' ', 0);
        } else {
            insertChar(s, ' ', len);
        }
        len++;
    }
}
