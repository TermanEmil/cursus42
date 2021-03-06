/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 00:37:36 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 12:03:10 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <limits.h>
# include "short_named_types.h"
# include "errno.h"

/*
** The makefile is possible hidden (.Makefile)
*/

# define CHR const char
# define FT_ABS(X)			((X < 0) ? (-X) : (X))
# define FT_SIGN_NOZERO(X)	((X < 0) ? (-1) : (1))
# define FT_SIGN(X)			((X == 0) ? (0) : (FT_SIGN_NOZERO(X)))
# define FT_MIN(X, Y)		((X < Y) ? (X) : (Y))
# define FT_MAX(X, Y)		((X > Y) ? (X) : (Y))

/*
** Error path
*/

# ifndef STDERR
#  define STDERR	2
# endif

# ifndef STDIN
#  define STDIN 0
# endif

# define CAST(a, t_type) ((t_type)(a))

/*
** List helpers
*/

# define LNEXT(list_cell)			((list_cell)->next)
# define LTONEXT(list_cell)			((list_cell) = LNEXT(list_cell))
# define LCONT(list_cell, t_type)	((t_type)((list_cell)->content))
# define LSTR(list_cell)			LCONT(list_cell, char*)

/*
** Dex helpers
*/

# define LDEX(t_list_cell)	LCONT(t_list_cell, t_dex*)
# define DEX_K(t_list_cell)	(LDEX(t_list_cell)->key)
# define DEX_V(t_list_cell)	(LDEX(t_list_cell)->value)

typedef struct s_list	t_list;

struct			s_list
{
	void		*content;
	size_t		content_size;
	t_list		*next;
};

typedef struct	s_ddata
{
	void		*content;
	size_t		size;
	size_t		d_size;
}				t_ddata;

typedef struct	s_dex
{
	void		*key;
	void		*value;
}				t_dex;

/*
** Project functions
*/

int				get_next_line(int const fd, char **line);
int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
int				ft_sprintf(char **buff, const char *format, ...);

/*
**	Memory function
*/

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memdup(void const *ptr, size_t size);

/*
** String functions
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchrnul(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *big, const char *lttl, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char sep);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strend(char *s);
char			*ft_strrev(char *str);
char			*ft_str_tolower(char *str);
char			*ft_str_toupper(char *str);

/*
** Special (string)
*/

void			ft_free_bidimens(char **table);
char			*ft_strrealoc(char **str);
int				ft_wstrlen(wchar_t *str);
void			ft_to_utf8(wchar_t c, t_uchar *buffer);
char			*ft_str_to_utf8(wchar_t *wstr, int nb_bytes);
int				ft_indexof(char **table, char *str);
int				ft_index_of_word(char *word, char *str, char *delims);
char			**ft_strtok(char const *s, const char *sep);
char			*ft_strmegajoin(int argc, ...);
char			*ft_strnchr(const char *s, char *chars);
void			ft_strdelif(char **str);
char			*ft_strreplace(char *dest, char *target, const char *str);
int				ft_strends_winth(char *str, char *end);
int				ft_match(char *s1, char *s2);

/*
** t_ddata
*/

void			ft_ddatainit(
						t_ddata *ddata,
						void *content,
						size_t size,
						size_t d_size);
int				ft_ddatarealloc(t_ddata *ddata, size_t required_size);
void			*ft_ddata_sizeadd(t_ddata *ddata);

/*
** ctype.h functions
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper (int c);
int				ft_tolower (int c);
int				ft_isupper(int c);
int				ft_islower(int c);

/*
**	List functions
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstlen(t_list *head);
void			ft_lst_push_front(t_list **first, t_list *new);
void			ft_lstreverse(t_list **head);
void			ft_lst_merge_sort(t_list **head, int (*f)(void*, void*));
t_list			*ft_lstget(t_list *head, int index);
void			ft_lstrm(t_list **h, t_list *trget, void (*del)(void*, size_t));

/*
** List helpers
*/

void			del_strlist_cell(void *data, size_t size);
void			ft_lst_memdel(void *content, size_t size);

/*
** Dex
*/

t_list			*dex_new(void *key, void *value);
void			**dex_getval(t_list *ldex, int (*cmp)(void*, void*), void *key);

/*
** Print functions
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnewl();

/*
** Other
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_bufitoa(long long n, char *buf);
void			print_n_times(char *str, int n, int fd);

#endif
