#include "stdio.h"

int     main(int argc, char **argv)
{
    char a = 'p';
    //char b = 'o';
    char c = 'p';

    int d;
    int e;
    argc ++;
    d = (int)a - (int)argv[1][1];
    e = (int)a - (int)c;
    printf("B is %i\n", d);
    printf("E is %i\n", e);
    return (0);
}