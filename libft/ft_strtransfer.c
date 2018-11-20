#include "libft.h"
#include <stdlib.h>

char      *ft_strtransfer(char *s1, char *s2, unsigned int a)
{
    char *str;

    str = ft_strjoin(s1, s2);
    if (a > 1)
    {
        free(s1);
        free(s2);
    }
    else
       free (s1);
    return (str);
}