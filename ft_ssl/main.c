#include "ft_ssl.h"
#include "extern.h"

comm_set comm_array[]= {
    {"md5", &md5_start, &handle_flags}/*
    {"sha256", &sha256_start, &handle_flags}*/
};

void       set_struct_data(int argc, char **argv, char *possible_str)
{
    int i;
    f_p flag;
    c_p command;

    i = 0;
    while (comm_array[i].com != '\0')
    {
        if (ft_strequ(comm_array[i].com, argv[1]) == 1)
        {
           flag = comm_array[i].flag_func;
           command = comm_array[i].comm_func;
        }
        i++;
    }
    //i = 0;
    //while (argv[i] != '\0')
    //{
        i = command(flag(argc, argv, possible_str)/*, argv*/);
        printf("I IS %i\n", i);
       // i++;
    //}
}
int      check_command(char **argv)
{
    int i;

    i = 0; 
    while (comm_array[i].com != '\0')
    {
        if (ft_strequ(comm_array[i].com, argv[1]) == 1)
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
    printf("GOOD1\n");
    if ((ret = check_command(argv)) == 0)
        return (0);
    if (argc < 2)
    {
        error_code(1);
        return (0);
    }
    printf("GOOD2\n");
    possible_str = check_error(argc,argv);
    set_struct_data(argc, argv, possible_str);

    return (0);
}