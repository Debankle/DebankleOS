#include "stdio.h"
#include "string.h"

// void printf(char *s, ...) {
//     char *printString;
//     char buffer[20];
//     void *beg = &s;
//     int i;
//     beg += sizeof(char*);
//     for (i = 0; i < strlen(s); i++) {
//         if (s[i] == '%') {
//             switch (s[i+1]) {
//                 case 's':
//                     printString += *(char*)beg;
//                     beg += sizeof(char*);
//                     break;
//                 case 'd':
//                     printString += *itoa((int)&beg, buffer);
//                     beg += sizeof(int);
//                     break;
//                 default:
//                     printString += *(char*)beg;
//                     beg += sizeof(char*);
//             }
//             i++;
//         } else {
//             printString += s[i];
//         }
//     }

//     kprint(printString);
// }

void printf(void *s, type_t t) {
    char *printString;
    char buffer[20];

    switch (t) {
        case TYPE_CHAR:
            printString = (char*)s;
            break;
        case TYPE_INT:
            printString = itoa(*((int *)s), buffer);
            break;
        default:
            printString = s;
    }

    kprint(printString);
}

uint8_t strlen(const char *s) {
    int l;
    for (l = 0; s[l] != '\0'; l++);
    return l;
}