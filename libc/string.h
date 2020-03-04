#ifndef OS_STRING
#define OS_STRING

#include "stdint.h"

void swap(char *x, char *y);
char *reverse(char *buffer, int i, int j);
char *itoa(int value, char *buffer);
int atoi(char *str);
void strcpy(char *destination, const char *source);

#endif // OS_STRING