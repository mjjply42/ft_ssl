#include "ft_ssl.h"

/*if argv reaches -P
stay at current index
run seperate hash immediately
clear stream
clear -P and any other flags //Nothing works on -P flags
clear digest

if argv reaches -S
set input equal next index
run hash
clear input
clear all flags
clear digest

after flag assingment, leave index on message content pusher. (basically what "flag or file/string" is last)*/

int    handle_opts(char **argv, m_s *data)
{
    int i;

    i = -1;
    while (('-' - argv[++i][0]) == 0)
    {
        if (((int)'p' - (int)argv[i][1]) == 0)
            data->flags[0] = 1;
        else if (((int)'r' - (int)argv[i][1]) == 0)
            data->flags[1] = 1;
        else if (((int)'q' - (int)argv[i][1]) == 0)
            data->flags[2] = 1;
        else if (((int)'s' - (int)argv[i][1]) == 0)
        {
            data->flags[3] = 1;
            return (i++);
        }
        else
        {
            printf("md5: illegal option -- %c\nusage: md5 [-pqrtx] [-s string] [files ...]", argv[i][1]);
            exit (0);
        }
    }
    if ((data->input = open_file(argv + i, 1)) == NULL)
                special_case(argv[i]);
    else
        return (i++);
    return (i);
}

m_s     *set_flags(m_s *message, char **argv)
{
    int i;

    i = 0;

    i += handle_opts(argv, message);
    argv += i;
    i += set_messages(message, argv);
}

/*-R and -Q apply throughout for every -S flag (string) or file 
    If -Q, delete -R permanently
-P unaffected by -Q and -R
**ONLY FREE (-S and -P)FLAGS AT LAST STEP BEFORE RETURN TO LOOP FUNCTION**/

/*main(int argc, char const *argv[])
{
    set hash_values early
    check errors
    set flags
    init whatever command
    update with new message to decode
    print digest
    return 0;
}*/

void       set_struct_data(int argc, char **argv, l_s *start_data)
{
    int i;
    f_p flag;
    c_p command;
    comm_set *array;

    i = 0;
    array = comm_array[i];
    while (array[i].com != '\0')
    {
        if (ft_strequ(array[i].com, argv[1]) == 1)
        {
            printf("1HELLO\n");
           flag = array[i].flag_func;
           command = array[i].comm_func;
        }
        i++;
    }
    i = 0;
    while (i < argc)
    {
        printf("%i and %i\n", i, argc);
        printf("ARGV IS %s\n", *(argv + i));
        i += command(flag(argc, argv + i, start_data), argv, argc);
        printf("I IS %i\n", i);
    }
}
       
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
            {
                info->stream = open_stream();
            }
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

int         main(int argc, char **argv)
{
    int ret;
    l_s *input;

    input = init_start_data();
    ret = 0;
    if ((ret = check_command(argv)) == 0)
        return (0);
    if (argc < 2)
    {
        error_code(1);
        return (0);
    }
    check_error(argc, argv, input);
    set_struct_data(argc, argv, input);

    return (0);

}