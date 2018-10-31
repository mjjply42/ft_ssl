#include "ft_ssl.h"


//Checks the stream and assigns value if available.
//If no input in STDIN, then program doesn not run*
//This is inline with the MD5 executable

char       *buff_manag(int length, char *buff, char *input)
{
    if (input == NULL)
    {
        input = ft_strnew(length);
        ft_memcpy(input, buff, length);
    }
    else
        input = ft_strtransfer(input, buff, 1);
    ft_memset(buff, 0, length);
    return (input);
}
char      *open_stream()
{
    size_t length = 1;
    char buff[1000];
    char *input;
    char *hold;

    input = NULL;
    while ((length = read(STDIN_FILENO, buff, 1000)) != 0)
        hold = buff_manag(length, buff, input);
    free(input);
    hold[ft_strlen(hold) - 1] = '\0';
    printf("length is %lu\n", ft_strlen(hold));
    return (hold);
}

char        *open_file(char **argv, int a)
{
    int fd;
    size_t length = 1;
    char buff[1000];
    char *input;
    char *hold;
    printf("ARGV3 is %s\n", (argv[0 + a]));
    input = NULL;
    fd = open((argv[0 + a]), O_RDONLY);
    if (fd < 0)
        return (NULL);
    while ((length = read(fd, buff, 1000)) != 0)
        hold = buff_manag(length, buff, input);
    free(input);
    printf("length is %lu\n,", ft_strlen(hold));
    return (hold);
}
