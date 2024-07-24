/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:12:13 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/16 16:27:45 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# define LOWER	"0123456789abcdef0x" // ft_printf
# define UPPER	"0123456789ABCDEF0X" // ft_printf

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdlib.h>	//malloc, free, exit
# include <unistd.h>	//read, write
# include <fcntl.h>		//fd
# include <stdarg.h>	//args

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_array_repeat(long int *arr, int size);

int			ft_atoi_hexa(const char *str);

int			ft_atoi(const char *str);

long int	ft_atol(const char *str);

void		ft_bzero(void *str, size_t n);

void		*ft_calloc(size_t nitems, size_t size);

int			ft_intabs(int nbr);

int			ft_intcmp(int a, int b, char comparison);

int			ft_intsign(int nbr);

int			ft_isalnum(int c);

int			ft_isalpha(int c);

int			ft_isascii(int c);

int			ft_isdigit(int c);

int			ft_ishexa(int c);

int			ft_isinteger(char *str);

int			ft_isprint(int c);

char		*ft_itoa(int n);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list		*ft_lstnew(void *content);

int			ft_lstsize(t_list *lst);

void		*ft_memchr(const void *str, int c, size_t n);

int			ft_memcmp(const void *str1, const void *str2, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t n);

void		*ft_memset(void *str, int c, size_t n);

void		ft_mtx_free(char **mtx);

int			ft_mtx_size(char **mtx);

void		ft_mtx_sort(char **key);

char		*ft_mtxstr(char **mtx);

int			ft_printf(const char *str, ...);

int			ft_pf_putchar(int c);

int			ft_pf_putnbr(int n, char flag);

int			ft_pf_putnbrbase(size_t n, char *tab, size_t base, char flag);

int			ft_pf_putptr(size_t address);

int			ft_pf_putstr(char *s);

void		ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

void		ft_putstr_fd(char *s, int fd);

int			ft_count_words(char const *s, char c);

char		**ft_split(char const *s, char c);

char		*ft_strchr(const char *str, int c);

int			ft_strcmp(char *s1, char *s2);

char		*ft_strdup(const char *str);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_strjoin(char const *s1, char const *s2);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);

size_t		ft_strlen(const char *str);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int			ft_strncmp(const char *str1, const char *str2, size_t n);

char		*ft_strnstr(const char *str, const char *to_find, size_t len);

char		*ft_strrchr(const char *str, int c);

char		*ft_strtrim(char const *s1, char const *set);

int			ft_strxchar(const char *str, char c);

char		*ft_substr_insert(char *str, int pos, int clear, char *sub);

char		*ft_substr_replace(char *str, char *old, char *new);

char		*ft_substr(char const *s, unsigned int start, size_t len);

void		ft_swap_int(int *a, int *b);

void		ft_swap_str(char **str1, char **str2);

int			ft_tolower(int c);

int			ft_toupper(int c);

char		*get_next_line(int fd);

#endif