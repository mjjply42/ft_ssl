#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# define S11 7
# define S12 12
# define S13 17
# define S14 22
# define S21 5
# define S22 9
# define S23 14
# define S24 20
# define S31 4
# define S32 11
# define S33 16
# define S34 23
# define S41 6
# define S42 10
# define S43 15
# define S44 21
# define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
# define ROTATE_RIGHT(x, n) (((x) >> (n)) | ((x) << (32-(n))))
# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTATE_RIGHT(x,2) ^ ROTATE_RIGHT(x,13) ^ ROTATE_RIGHT(x,22))
# define EP1(x) (ROTATE_RIGHT(x,6) ^ ROTATE_RIGHT(x,11) ^ ROTATE_RIGHT(x,25))
# define SIG0(x) (ROTATE_RIGHT(x,7) ^ ROTATE_RIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTATE_RIGHT(x,17) ^ ROTATE_RIGHT(x,19) ^ ((x) >> 10))
# define RIGHT_SHIFT(x, n) ((x) >> (n))
# define LEFT_SHIFT(x, n) ((x) << (n))


typedef struct main_info
{
    char                 *com;
    char                 *input;
    char                 flags[4];
    char                 *stream;
    int                  count;
    bool                 STREAMS;
    unsigned long long   bit_size;
    bool                 FILES;
    char                *file_name;
    unsigned char       *digest;
    bool                s_error;
}                        m_s;

typedef struct	h_i
{
	uint32_t	(*f)(uint32_t a, uint32_t b, uint32_t c);
	int		    block;
	int		    step;
	uint32_t	signed_constant;
}				md5_f;

typedef struct hashing
{
    uint32_t           message[128];
    uint32_t           exp_message[128];
    uint32_t           a;
    uint32_t           b;
    uint32_t           c;
    uint32_t           d;
    uint32_t           e;
    uint32_t           f;
    uint32_t           g;
    uint32_t           h;
}                      h_s;

//Dispatch pointer for the flags, and to assign them
typedef m_s *(*f_p)(int argc, char **argv, char *str);
typedef int (*c_p)(m_s *pre_image_data, char **argv);

typedef struct to_comm
{
    char    *com;
    c_p     comm_func;
    f_p     flag_func;
}           comm_set;

m_s       *init_message_data();
m_s       *set_flags(m_s *message, char **argv);
m_s       *handle_flags(int argc, char **argv, char *str);
m_s	      *padding(m_s *pre_image);
char      *check_error(int argc, char **argv);
char      *open_file(char **argv, int a);
char      *open_stream();
char      *buff_manag(int length, char *buff, char *input);
unsigned char      *md5_hash(unsigned char *message, unsigned long long byte_count);
unsigned char      *sha256_hash(unsigned char *message, unsigned long long byte_count);
void      print_command_opt();
void      set_struct_data(int argc, char **argv, char *possible_str);
void      error_code(int a);
void      special_case(char *str);
void      destroy_data(m_s *pre_image);
void      print_digest(unsigned char *digest, m_s *pre_image, char **argv);
void      start_rounds(h_s *hash);
void	  md5_process(h_s *hash, uint32_t *state);
int       md5_pad_start(m_s *pre_image_data, char **argv);
int       sha256_pad_start(m_s *pre_image, char **argv);
int       check_command(char **argv);
int       set_messages(m_s *message, char **argv);
int       handle_opts(char **argv, m_s *message);

#endif