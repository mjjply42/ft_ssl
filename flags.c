#include "ft_ssl.h"
#include "extern.h"

//comm_set comm_array[3][2];

/*int    set_messages(m_s *message, char **argv)
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
}*/
void   set_messages(m_s *pre_data, char **argv)
{
    printf("*****SET MESSAGES*****\n");
    if (pre_data->flags[0] == 1)
    {
        printf("1HERE\n");
        pre_data->stream = open_stream();
    }
    if (pre_data->flags[2] == 1)
    {
        printf("2HERE\n");
        pre_data->flags[1] = 0;
        if (pre_data->flags[0] == 0)
            pre_data->input = open_stream();
    }
    if (pre_data->flags[3])
    {
        printf("3HERE\n");
        ft_memcpy(pre_data->input = ft_strnew(ft_strlen(*(argv))), 
        (*(argv)), ft_strlen(*(argv)));
        if (pre_data->input == NULL)
            error_code(3);
    }
    else if ((pre_data->input = open_file(argv, 0)) == NULL)
    {
        printf("4HERE\n");
        special_case(*argv, 0);
        if (pre_data->input)
        {
            pre_data->FILES = TRUE;
            pre_data->file_name = *argv;
        }
    }
    else
    {
        printf("4HERE\n");
        pre_data->input = open_stream();
    }
}

int    handle_opts(char **argv, m_s *data)
{
    printf("*****HANDLE OPTS*****\n");
    int i;

    i = 0;
    while (i < 3)
    {   printf("I is %i\n", i);
        printf("ARGV is %s\n", *(argv + i));
        while (('-' - argv[i][0]) == 0)
        {
            if (((int)'p' - (int)argv[i][1]) == 0)
            {
                printf("P!\n");
                data->flags[0] = 1;
            }
            else if (((int)'r' - (int)argv[i][1]) == 0)
                data->flags[1] = 1;
            else if (((int)'q' - (int)argv[i][1]) == 0)
                data->flags[2] = 1;
            else if (((int)'s' - (int)argv[i][1]) == 0)
            {
               data->flags[3] = 1;
               return (++i);
            }
            else
                special_case(argv[i], 1);
            i++;
        }
        if (*argv[i] == '\0')
            break;
        i++;
    }
    if ((data->input = open_file(argv + i - 1, 1)) == NULL)
    {       
            printf("HERE\n");
            special_case(argv[i], 0);
    }
    else
        return (i++);
    return (i);
}

/*int    handle_opts(char **argv, m_s *message)
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
}*/

m_s     *set_flags(m_s *message, char **argv)
{
    printf("*****SET FLAGS*****\n");
    int i;

    i = 0;

    i += handle_opts(argv, message);
    printf("I is %i\n", i);
    printf("1HERE\n");
    argv += i;
    printf("ARGV IS %s\n", *argv);
    printf("-P = %i\n-Q = %i\n-R = %i\n-S = %i\n", message->flags[0], message->flags[2], message->flags[1], message->flags[3]);
    set_messages(message, argv);
    printf("2HERE\n");
    message->count = i;
    printf("\n\n");
    return (message);
}

void       copy(m_s *message, l_s *pre_data)
{   
    printf("*****COPY*****\n");
    if (pre_data->input != NULL)
    {
        printf("1HERE\n");
        ft_memcpy(message->input = ft_strnew(ft_strlen(pre_data->input)), pre_data->input, ft_strlen(pre_data->input));
    }
    if (pre_data->stream != NULL)
    {
        printf("2HERE\n");
        ft_memcpy(message->stream = ft_strnew(ft_strlen(pre_data->stream)), pre_data->stream, ft_strlen(pre_data->stream));
    }
    printf("3HERE\n");
    //printf("pre dat len is %zu\n", ft_strlen(pre_data->com));
    ft_memcpy(message->com = ft_strnew(ft_strlen(pre_data->com)), pre_data->com, ft_strlen(pre_data->com));
    message->file_name = pre_data->file_name;
    message->com = pre_data->com;
    message->FILES = pre_data->FILES;
    message->count = pre_data->count;
}
/*void    count(m_s *message, int argc)
{
        if (argc == 2)
            message->count = argc - 1;
        else if (argc == 3)
        {
            message->count = argc - 1;
        }
        printf("mc is %i\n", message->count);
}
m_s     *handle_flags(int argc, char **argv, l_s *pre_data)
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
    printf("ARGV57890 is %s\n", *argv);
    return (message);
}*/
m_s        *handle_flags(int argc, char **argv, l_s *pre_data)
{
    printf("*****HANDLE FLAGS*****\n");
    m_s *message;
    

    message = init_message_data();
    //printf("pre dat len is %zu\n", ft_strlen(pre_data->com));
    if (argc <= 3)
        copy(message, pre_data);
    printf("YO\n");
    if (argc > 3)
    {
        set_flags(message, argv);
        message->com = ft_strdup(pre_data->com);
    }
    //destroy_pre(pre_data);
    printf("MESAAGE COUNT IS %i\n" ,message->count);
    argv += message->count;
    printf("FILE %i\n", message->FILES);
    printf("STREAMS %s\n", message->stream);
    printf("INPUT %s\n", message->input);
    printf("ARGV57890 is %s\n", *argv);
    printf("COMM is %s\n", message->com);
    printf("\n\n");
    return (message);
}