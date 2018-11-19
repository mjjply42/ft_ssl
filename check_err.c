#include "ft_ssl.h"

//Error printing to display available COMMANDS
void      print_command_opt()
{
    char stand_comm[] = "";
    char digest_comm[] = {"sha256 " "md5 "};
    char cipher_comm[] = "";

    printf("ft_ssl: ERROR: argument is an invalid command\n\n \
!!!USE THE CORRECT CASE **** a != A **** !!!! \
 STANDARD COMMANDS:\n \
 %s\n\n", stand_comm);
    printf("MESSAGE DIGEST COMMANDS:\n\n \
%s\n\n", digest_comm);
    printf("CIPHER COMMANDS:\n\n \
%s\n\n", cipher_comm);
}

//Checks input against first argument in dispatch table array
//If valid, passes. Otherwise, error print(print_command_opt).
//Checks all argument counts
void        error_code(int a)
{
    if (a == 1)
        printf("usage: ft_ssl command [command opts] [command args]\n");
    if (a == 2)
        print_command_opt();
    if (a == 3)
    {
        printf("md5: option requires an argument -- s\nusage:\
 md5 [-pqrtx] [-s string] [files ...]\n");
        exit(0);
    }
}
void        special_case(char *argv, int a)
{
    if (a == 0)
        printf("md5: %s: No such file or directory\n", argv);
    if (a == 1)
    {
        printf("md5: illegal option -- %c\nusage: \
        md5 [-pqrtx] [-s string] [files ...]", argv[1]);
        exit (0);
    }
}
/*char       *check_error(int argc, char **argv)
{
    int ret;
    char *input;

    input = NULL;
    ret = 0;
    if (argc == 2)
    {
        input = open_stream();
        printf("input is %s\n", input);
    }
    if (argc == 3)   
    {
        if ((ft_strequ("-s",argv[2])) == 0)
        {
            if ((input = open_file(argv, 2)) == NULL)
                input = open_stream();
        }
        else
        {
            error_code(3);
            exit(0);
        }
    }
    return (input);
}*/

void        check_error(int argc, char **argv, l_s *info)
{
    if (argc == 2)
        info->stream = open_stream();
    if (argc == 3)
    {
        if ((ft_strequ("-s", argv[2])) == 0)
        {
            info->input = open_file(argv, 2);
            if (info->input == NULL)
                info->stream = open_stream();
            else
            {
                info->file_name = argv[2];
                info->FILES = TRUE;
            }
        }
        else
        {
            error_code(3);
            exit(0);
        }
    }
    
}