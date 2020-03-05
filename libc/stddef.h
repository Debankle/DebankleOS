#ifndef OS_STDDEF_H
#define OS_STDDEF_H

#define NULL ((void *)0)

typedef unsigned int size_t;
typedef enum { false, true } bool;
typedef enum { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_BOOL } type_t;

#endif // OS_STDDEF_H