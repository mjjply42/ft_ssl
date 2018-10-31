#include "ft_ssl.h"
#include "extern.h"

comm_set arr[] = {
    {"md5", &md5_start, &handle_flags}/*
    {"sha256", &sha256_start, &handle_flags}*/
};

int    set_messages(m_s *message, char **argv)
{
    int i;
    
    i = 0;
    if ((message->flags[0] == 1 || message->flags[1] == 1 || \
    message->flags[2] == 1) && (!message->STREAMS))
    {
        message->stream = open_stream();
        message->STREAMS = TRUE;
    }
    if (message->flags[3] == 1)
    {
        if ((message->input = open_file(argv, 1)) == NULL)
            message->input = *(argv + 1);
        else
        {   
            message->FILES = TRUE;
        }
        if (message->input == NULL)
            error_code(3);
        i++;
    }
    if ((message->flags[2] && message->flags[1]) == 1)
        message->flags[1] = 0;
    return (i);
}

int    handle_opts(char **argv, m_s *message)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
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
        i++;
    }
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
        if (argv[i][0] == '-')
        {
            i += handle_opts((argv + i), message);
            if (message->flags[3] == 1)
                break;
            break;
        }
        i++;
    } 
    printf("I is %i\n", i);
    i += set_messages(message, (argv + i));
    argv += i;
    message->count = i;
    return (message);
}

m_s     *handle_flags(int argc, char **argv, char *str)
{
    m_s *message;
    int i;
    
    i = -1;
    message = init_message_data();
    while (arr[++i].com  != '\0')
        if (ft_strequ(arr[i].com, argv[1]) == 1)
            message->com = arr[i].com;
    if (argc == 3)
    {
        if ((ft_strequ("-", argv[2])) != 1)
            message->FILES = TRUE;
    }
    if (argc < 3)
        message->input = ft_strnew(ft_strlen(str));
    if (argc > 3)
       set_flags(message, argv);
    else   
        ft_memcpy((message->input = ft_strnew(ft_strlen(str))), str, ft_strlen(str));
    free(str);
    argv += message->count;
     printf("Count is %i\n", message->count);
    return (message);
}