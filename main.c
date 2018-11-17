#include "ft_ssl.h"
#include "extern.h"

comm_set comm_array[3][2] = {
    {{"md5", &md5_pad_start, &handle_flags},
    {"sha256", &sha256_pad_start, &handle_flags}}
};
void       cycle(unsigned char *digest)
{
    int a;

    a = -1;
    while (++a < 32)
        printf("%x", digest[a]);
}
void        print_digest(unsigned char *digest, m_s *pre_image, char **argv)
{

    if (pre_image->flags[0] != 0)
    {
        printf("%s", pre_image->stream);
        cycle(digest);
        pre_image->flags[0] = 0;
    }
    else if ((pre_image->FILES != FALSE || pre_image->flags[3] != 0) && pre_image->flags[1] == 0)
    {
        if (pre_image->s_error == TRUE)
            error_code(3);
        printf("%s (\"%s\") = ", argv[1], (pre_image->FILES == FALSE)? 
        pre_image->input : *(argv + pre_image->count));
        cycle(digest);
    }
    else if (pre_image->flags[1] != 0 && pre_image->flags[2] == 0)
    {
        cycle(digest);
        printf(" \"%s\"", (pre_image->file_name == NULL)? pre_image->input : pre_image->file_name);
    }
    else if (pre_image->flags[0] != pre_image->flags[3])
        cycle(digest);
    else 
        cycle(digest);
    printf("\n");
}

void       set_struct_data(int argc, char **argv, char *possible_str)
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
        i += command(flag(argc, argv + i, possible_str), argv, argc);
        printf("I IS %i\n", i);
    }
}
int      check_command(char **argv)
{
    int i;
    comm_set *array;

    i = 0;
    array = comm_array[i];
    while (array[i].com != '\0')
    {
        if (ft_strequ(array[i].com, argv[1]) == 1)
            return (1);
        i++;
    }
    error_code(2);
    return (0);
}

int        main(int argc, char **argv)
{
    int ret;
    char *possible_str;
    
    possible_str = NULL;
    ret = 0;
    printf("ARGC is %i\n", argc);
    if ((ret = check_command(argv)) == 0)
        return (0);
    if (argc < 2)
    {
        error_code(1);
        return (0);
    }
    //printf("ARGC is %d\n", argc);
    possible_str = check_error(argc,argv);
    set_struct_data(argc, argv, possible_str);

    return (0);
}