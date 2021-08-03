/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:32:51 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 21:39:24 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# include "get_next_line.h"
# include "ft_printf.h"

# define FREE 1
# define DONTFREE 0

typedef struct		s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}					node;

int					ft_chrcount(int c, char *str);
int					ft_chrindex(int c, char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isspacenl(int c);

node				*ft_lst_back (node *nil);
void				ft_lst_clear (node *nil);
void				ft_lst_del (node *nil, node *nd);
void				ft_lst_delhard (node *nil, node *nd);
node				*ft_lst_empty (node *lst);
node				*ft_lst_front (node *nil);
node				*ft_lst_init (void);
void				ft_lst_iter (node *nil, void (*f)(void *));
node				*ft_lst_min (node *lst, int (*cmp)(void *, void *));
node				*ft_lst_new (void *data);
void				ft_lst_pushback (node *nil, node *new);
void				ft_lst_pushfront (node *nil, node *new);
void				ft_lst_rev (node *lst);
int					ft_lst_size (node *nil);
node				*ft_lst_sort (node *lst, int (*cmp)(void *, void *));

int					ft_nbrlen(long n);
int					ft_hexlen(long n);
int					ft_baselen(long n, int base);
int					ft_power(int nbr, int pow);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memdel(void *ptr);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

void				ft_putchar(char c);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

void				ft_skip_space(const char *str, int *i);
void				ft_skip_spacenl(const char *str, int *i);
void				ft_skip_char(const char *str, int *i, char c);
void				ft_skip_chars(const char *str, int *i, char *base);

char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinf (char *s1, int f1, char *s2, int f2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
#endif
