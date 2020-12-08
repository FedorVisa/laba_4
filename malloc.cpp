#include<stdio.h>
#include<stdlib.h>

char character[] = { 'A','a','E','e','Y','y','U','u','I','i','O','o' };

int Checklet(char d) {
    return ((d >= 'a') && (d <= 'z') || ((d >= 'A') && (d <= 'Z')));
}

int isVowel(char a) {
    for (size_t i = 0; i < sizeof(character); i++) {
        if (a == character[i]) {
            return 1;
        }
    }
    return 0;
}

int vowelcount(char* a) {
    int i = 0;
    int count = 0;
    while (a[i] != '\0') {
        if (isVowel(a[i])) {
            count++;
        }
        i++;
    }
    return count;
}

void swap(char** a, char** b) {
    char* c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

char* get_string(int* len) {
    *len = 0; 
    int capacity = 1; 
    char* s = (char*)malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        s[(*len)++] = c; 
        if (*len >= capacity) {
            capacity *= 2;
            s = (char*)realloc(s, capacity * sizeof(char)); 
        }
        c = getchar();               
    }
    s[*len] = '\0'; 
    return s; 
}

int main() {
    int i, size;
    int blen;
    int words=0;
    printf(" enter string\n");
  
    char* s = get_string(&blen);
 
    for (i = 0; i < blen; ++i) {
        if (!Checklet(s[i])) { s[i] = '\0'; 
        words++;
        }
    }
    char** array = (char**)malloc(words*sizeof(char*));
    for (i = 0, size = 0; i <blen; ++i) {
        if (s[i] != '\0') {
            array[size++] = &s[i];
            while (s[i] != '\0')++i;     
        }
    }
    for (i = 0; i < size-1; ++i) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vowelcount(array[j]) > vowelcount(array[j + 1]))
                swap(&array[j], &array[j + 1]);
        }
    }
    for (i = 0; i < size; ++i) {
        puts(array[i]);
    }
    free(s);
    return 0;
}