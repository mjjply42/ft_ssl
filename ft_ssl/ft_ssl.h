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
# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))
# define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
# define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
}
# define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
}
# define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
}
# define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
}
typedef struct		s_mem
{
	unsigned char	*data;
	unsigned int	h[8];
	int				len;
}					t_mem;

typedef struct input_info
{
    char                 *com;
    char                 *input;
    char                 flags[4];
    char                 *stream;
    int                  count;
    bool                 STREAMS;
    ULL   bit_size;
    bool                 FILES;

} m_s;

typedef struct		s_i
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	t;
	unsigned int	t2;
} t_i;

typedef struct after_image
{
    unsigned long long state[4];
    uint32_t message[16];
    unsigned char *digest;

} h_s;

//Dispatch pointer for the flags, and to assign them
typedef m_s *(*f_p)(int argc, char **argv, char *str);
typedef int (*c_p)(m_s *pre_image_data/**, char **argv**/);

typedef struct to_comm
{
    char    *com;
    c_p     comm_func;
    f_p     flag_func;

} comm_set;

m_s       *init_message_data();
m_s       *set_flags(m_s *message, char **argv);
m_s       *handle_flags(int argc, char **argv, char *str);


char      *check_error(int argc, char **argv);
char      *open_file(char **argv, int a);
char      *open_stream();
char      *buff_manag(int length, char *buff, char *input);
int       md5_start(m_s *pre_image_data/*, char **argv*/);
//char        *sha256_start(int argc, char **argv, char *str);

void      print_command_opt();
void      set_struct_data(int argc, char **argv, char *possible_str);
void      error_code(int a);
void      special_case(char *str);
//void      padding(ULL pre_pad_size, m_s *pre_image);
t_mem	*padding(m_s *pre_image);
void      md5_hash(unsigned char *message, ULL byte_count);
void      start_rounds(h_s *hash);

int       check_command(char **argv);
int       check_command(char **argv);
int       set_messages(m_s *message, char **argv);
int       handle_opts(char **argv, m_s *message);


#endif