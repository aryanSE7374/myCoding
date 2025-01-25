// fun to swap two integers by reference

// #include "c1.c"




void fun(int *a, int *b)
{
    *a = *a + *b ;
    *b = *a - *b ;
    *a = *a - *b ;
}