/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:19:06 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/04/10 16:28:52 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h> //malloc, free, size_t, NULL
# include <stdint.h> //SIZE_MAX
# include <limits.h> //INT_MAX
# include <string.h> //strdup
# include <unistd.h> //write, read
# include <stdio.h> //printf
# include <fcntl.h> //open, close
# include <stdarg.h> //va_start, va_arg, va_copy, va_end

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 //gnl
# endif

# ifndef MAX_FD
#  define MAX_FD 1024 //gnl bonus
# endif

# ifndef LOW_HEXBASE
#  define LOW_HEXBASE "0123456789abcdef" //printf %x
# endif

# ifndef UPP_HEXBASE
#  define UPP_HEXBASE "0123456789ABCDEF" //printf %X
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//new functions added
char	*ft_get_next_line(int fd);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_base(unsigned long lnb, char *base);
int		ft_printf(const char *str, ...);
char	*ft_str_rm_dup(char *str, char c);
void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_matrix(char **array);

//printf utils
int		ft_printlen(const char *str);
int		ft_print_char(va_list args);
int		ft_print_str(va_list args);
int		ft_print_nbr(va_list args, const char format, char *flag_buffer);
int		ft_printnbr_base16(va_list args, char *base, char *flag_buffer);
int		ft_print_ptr(va_list args);
int		ft_check_flags(const char *format);
char	*ft_get_flag(const char *format);

#endif 
