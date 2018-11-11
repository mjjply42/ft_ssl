/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:04:16 by majones           #+#    #+#             */
/*   Updated: 2018/10/17 20:08:51 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define MIN_INT -2147483648
# define MAX_INT 214748364
# define TRUE 1
# define FALSE 0
# define SPACE ft_putchar(' ');
# define NEW_LINE ft_putchar('\n');
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putwchar(wchar_t c);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *str, int x, size_t len);
void				*ft_memalloc(size_t size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				ft_find_ret_char(char *src, int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned int n, int base);
char				*ft_sitoa(intmax_t n);
char				*ft_nextword(char *str);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_uitoa(uintmax_t n);
char				*ft_uitoa_base(uintmax_t n, int base);
char				*ft_addprefix(char *pre, char *str);
char				*ft_capitalize(char *str);
char				*ft_nextspace(char *str);
char      			*ft_strtransfer(const char *s1, const char *s2, unsigned int a);
unsigned char		*ft_uint32_to_chr(unsigned char *output, uint32_t *input , unsigned int len);
unsigned char       *bytes2_nibl_2chr(unsigned char *before, unsigned char *after);
int					ft_atoi(const char *str);
int					ft_bintodec(int binary);
int					ft_dectobin(int dec);
int					ft_isalnum(int c);
int					ft_posintlen(uintmax_t c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_wordcount(char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
unsigned int 		swap_byte_uint(unsigned int a);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
uint32_t			*ft_char_to_uint32(uint32_t *output, unsigned char *input, unsigned int len);
t_list				*ft_lstnew(void const*content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
