#ifndef OS_STDLIB
#define OS_STDLIB

int abs(int N)
{
    return ((N<0)?(-N):(N));
}

// #define sizeof(object) (char*)(&object+1)-(char*)(&object)

#endif // OS_STDLIB