#include "ft_ssl.h"

/*if argv reaches -P
stay at current index
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
void   set_messages(m_s *pre_data, char **argv)
{
    if (pre_data->flags[0] == 1)
        pre_data->stream = open_stream();
    else if (pre_data->flags[2] == 1)
        pre_data->flags[1] = 0;
        if (pre_data->flags[0] = 0)
            pre_data->input = open_stream();
    else if (pre_data->flags[3] == 1)
        ft_memcpy(pre_data->input = ft_strnew(ft_strlen(*argv + 1)), 
        (*argv + 1), ft_strlen(*argv + 1));
        if (pre_data->input == NULL)
            error_code(3);
    else if ((pre_data->input = open_file(argv, 0)) == NULL)
    {
        special_case(*argv, 0);
        if (pre_data->input)
        {
            pre_data->FILES = TRUE;
            pre_data->file_name = *argv;
        }
    }
    else
        pre_data->input = open_stream();
}

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
            special_case(argv[i], 1);
    }
    if ((data->input = open_file(argv + i, 1)) == NULL)
            special_case(argv[i], 0);
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
    set_messages(message, argv);
    message->count = i;
    return (message);
}
void       copy(m_s *message, l_s *pre_data)
{   if (pre_data->input != NULL)
        ft_memcpy(message->input, pre_data->input, ft_strlen(pre_data->input));
    if (pre_data->stream != NULL)
        ft_memcpy(message->stream, pre_data->stream, ft_strlen(pre_data->stream));
    message->file_name = pre_data->file_name;
    message->com = pre_data->com;
    message->FILES = pre_data->FILES;
}
m_s        *handle_flags(int argc, char **argv, l_s *pre_data)
{
    m_s *message;
    int i;

    message = init_message_data();
    if (argc <= 3)
        copy(message, pre_data);
    if (argc > 3)
        set_flags(message, argv);
    destroy_pre(pre_data);
    argv += message->count;
    if (message->input != NULL)
        message->STREAMS = TRUE;
    printf("FILE %i\n", message->FILES);
    printf("STREAMS %s\n", message->stream);
    printf("INPUT %s\n", message->input);
    printf("ARGV57890 is %s\n", *argv);
    return (message);
}

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
            start_data->com = array[i].com;
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