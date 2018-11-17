#include "ft_ssl.h"
#include "extern.h"

comm_set comm_array[3][2];

int    set_messages(m_s *message, char **argv)
{
    int i;
    printf("HERE456\n");
    i = 0;
    printf("P: %i\nR:  %i\nS:  %i\nQ:  %i\n", (int)message->flags[0], (int)message->flags[1], (int)message->flags[3], (int)message->flags[2]);
    if ((message->flags[0] == 1 || message->flags[1] == 1 || \
    message->flags[2] == 1))
    {
        if (message->flags[0] == 0 && message->flags[3] == 1)
            message->STREAMS = FALSE;
        else
        {
            message->stream = open_stream();
            message->STREAMS = TRUE;
        }
    }
    if (message->flags[3] == 1)
    {
        printf("3ARGV is %s\n", *(argv + 1));
        message->input = *(argv + 1);
        if (message->input == NULL)
            message->s_error = TRUE;
        i++;
    }
    else
    {   if ((message->input = open_file(argv, 0)) != NULL)
        {
            message->FILES = TRUE;
            message->file_name = *(argv + 1);
            //printf("1INPUT is %s\n", message->input);
            return (i);
        }
    }
    i++;
    return (i);
}

int    handle_opts(char **argv, m_s *message)
{
    int i;

    i = 0;
        printf("I IS %i\n", i);
        printf("ARGVFUCK %s\n", argv[i]);
        if ((ft_strcmp("-p", argv[i])) == 0)
            message->flags[0] = 1;
        else if ((ft_strcmp("-r", argv[i])) == 0)
            message->flags[1] = 1;
        else if ((ft_strcmp("-q", argv[i])) == 0)
            message->flags[2] = 1;
        else if ((ft_strcmp("-s", argv[i])) == 0)
        {
            message->flags[3] = 1;
            return(i++);
        }
        else
            if ((message->input = open_file((argv + i), 0)) == NULL)
                special_case(argv[i]);
    printf("ERER\n");
    return (i);
}

m_s     *set_flags(m_s *message, char **argv)
{
    int i;
    int j;
    
    j = 0;
    i = 0;
    
    while (argv[i] != '\0')
    {  
        printf("yonigg %s\n", argv[i]);
        if (argv[i][0] == '-')
        {
            printf("tytuARGV IS %s\n", *(argv + i));
            i += handle_opts((argv + i), message);
            if (message->flags[3] == 1)
                break;
            printf("Exce\n");
            break;
        }
        //printf("ARGC is %i\n", argc);
        i++;
        printf("I is %i\n", i);
    } 
    printf("$I is %i\n", i);
    printf("1ARGV is %s\n", *(argv));
    i += set_messages(message, (argv + i));
    printf("$$I is %i\n", i);
    argv += i;
    if (message->flags[3] == 1)
        argv -= 1;
    printf("wdARGV IS %s\n", *argv);
    message->count = i;
    return (message);
}
void    count(m_s *message, int argc)
{
        if (argc == 2)
            message->count = argc - 1;
        else if (argc == 3)
        {
            message->count = argc - 1;
        }
        printf("mc is %i\n", message->count);
}
m_s     *handle_flags(int argc, char **argv, char *str)
{
    m_s *message;
    int i;
    comm_set *arr;
    
    i = -1;
    arr = comm_array[i + 1];
    message = init_message_data();
    while (arr[++i].com  != '\0')
        if (ft_strequ(arr[i].com, argv[1]) == 1)
            message->com = arr[i].com;
    printf("ARGV IS NOW %c\n", argv[0][0]);
    if (argc == 3)
        if ((ft_strcmp("-", &argv[2][0]) == 1))
            message->FILES = TRUE;
    if (argc < 3)
        message->input = ft_strnew(ft_strlen(str));
    if (argc > 3)
       set_flags(message, argv);
    else
        (argc == 3 && message->FILES == FALSE)? ft_memcpy((message->stream 
        = ft_strnew(ft_strlen(str))), str, ft_strlen(str)) : ft_memcpy((message->input
        = ft_strnew(ft_strlen(str))), str, ft_strlen(str));
    free(str);
    count(message, argc);
    argv += message->count;
    printf("FILE %i\n", message->FILES);
    printf("STREAMS %s\n", message->stream);
    printf("INPUT %s\n", message->input);
    //printf("ARGV57890 is %s\n", *argv);
    return (message);
}