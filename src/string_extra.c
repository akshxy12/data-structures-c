#include "../include/string_extra.h"

int strcmp_case_insensitive(const char* str1, const char* str2) {
    char *s1 = str1;
    char *s2 = str2;
    int compare = 0;

    for(int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        compare = tolower(s1[i]) - tolower(s2[i]);

        if(compare != 0) return compare;
    }

    return compare;
}