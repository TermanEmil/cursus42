/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:15:00 by eterman           #+#    #+#             */
/*   Updated: 2016/12/30 19:42:20 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <dirent.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <time.h>
# include <sys/ioctl.h>

/*
** Extra options:
** -G - no groups
** -e - no colors
*/

# define FT_MAJOR(x)	((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define FT_MINOR(x)	((int32_t)((x) & 0xffffff))
# define SFIFO			struct s_fileinfo

/*
** Time options
*/

# define TIME_LAST_ACCESS		'a'
# define TIME_LAST_STAT_CHANGE	'c'
# define TIME_LAST_MODIF		'm'

/*
** List helpers
*/

# define L_CONTENT(type, head)	((type)(head->content))
# define L_NEXT(cell)			((cell)->next)
# define FINFO(cell)			(L_CONTENT(t_fileinfo*, cell))
# define TPARTS					t_time_parts

/*
** Colors
*/

# define CL_EOC			"\x1B[0m"
# define CL_NOCL		"0"
# define CL_DIR			"01;34"
# define CL_SYMLINK		"01;36"
# define CL_PIPE		"33"
# define CL_SOCKET		"01;35"
# define CL_BLKDEVICE	"01;33"
# define CL_CHRDEVICE	"01;33"
# define CL_UNDEF_FILE	"rgb160"
# define CL_ORPHAN_LINK	"rgb196"
# define CL_EXECUTABLE	"01;32"
# define CL_DOOR		"01;35"
# define CL_SETUID		"37;41"
# define CL_SETGID		"30;43"
# define CL_STICKY		"37;44"
# define CL_C_FILE		"rgb93"
# define CL_O_FILE		"rgb245"
# define CL_H_FILE		"rgb11"
# define CL_MAKEFILE	"rgb82"
# define CL_ROOT		"rgb21"

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

/*
** I may have a file from future (year: 999999999).
** which_time can be {TIME_LAST_ACCESS,
** TIME_LAST_STAT_CHANGE and TIME_LAST_MODIF}.
*/

typedef struct	s_time_parts
{
	char		which_time;
	char		day[5];
	char		month[4];
	char		nr_day[3];
	char		clock[6];
	char		year[10];
	char		clock_or_year[10];
}				t_time_parts;

/*
** I could easily add -h options, because the size is stored as a string.
*/

typedef struct	s_fileinfo
{
	char		*name;
	char		*link_path;
	SFIFO		*followed_link;
	char		file_type;
	char		modes[11];
	char		file_size[32];
	TPARTS		time_parts;
	t_stat		stat;
	int			color_on;
	char		*group;
	char		*user;
	int			major;
	int			minor;
	int			name_should_be_modified;
}				t_fileinfo;

typedef struct	s_ls_data
{
	int			should_print_name;
	int			is_the_first;
	char		options[15];
	int			list_rec;
	int			list_hidden;
	char		**argv;
	int			argc;
}				t_ls_data;

typedef struct	s_max_len
{
	int			modes;
	int			nr_links;
	int			user;
	int			group;
	int			major;
	int			minor;
	int			maj_and_min;
	int			size;
}				t_max_len;

/*
** ft_ls
*/

int				its_option_field(char *field);
int				extract_argv_options(t_ls_data *ls_data, int *valid_argv);
void			ft_ls_dir(char *path, t_ls_data *ls_data);
t_ull			count_blocks(t_list *files);
void			get_max_lenghts(t_list *file_infos, t_max_len *max);
void			print_aligned_fileinfo(
					t_fileinfo *fileinfo,
					t_max_len *max_lens,
					t_ls_data *ls_data);
void			listed_print(t_list *file_infos, t_ls_data *ls_data);
int				should_follow_link(t_ls_data *ls_data);
void			simple_print(t_list *files, t_ls_data *ls_data);
void			fileinfo_sort_list(t_list **files, t_ls_data *ls_data);
void			ft_ls_given_files(t_list *files, t_ls_data *ls_data);
t_list			*extract_all_from_path(char *path, t_ls_data *ls_data);
char			*ft_readlink(char *path, ssize_t starting_size);
void			check_files_for_existance(int ac, char **av, int *valid_argv);
void			extract_args(int *vd, t_ls_data *d, t_list **fls, t_list **drs);
int				handle_no_args_case(t_ls_data *ls_data, t_list **dirs);
t_fileinfo		*follow_all_links(t_fileinfo *fileinfo);

/*
** Print functions
*/

void			print_type(t_fileinfo *fileinfo, t_ls_data *ls_data);
void			print_name(t_fileinfo *f, t_ls_data *d, int m, int left_pivot);
void			print_link(t_fileinfo *fileinfo, t_ls_data *ls_data);
void			print_user(t_fileinfo *f, t_ls_data *dta, t_max_len *lns);
void			print_grp(t_fileinfo *f, t_ls_data *ls_data, t_max_len *lns);

/*
** form_fileinfo
*/

int				form_fileinfo(CHR *f_name, t_fileinfo *finfo, int link_follow);
char			*form_modes(t_fileinfo *fileinfo);
char			get_file_type_by_stat(t_stat *buff);
int				get_file_owner(t_fileinfo *fileinfo);
int				get_file_group(t_fileinfo *fileinfo);
void			get_file_size(t_fileinfo *fileinfo);
void			get_file_time(t_fileinfo *fileinfo);
void			process_clock_or_year(t_fileinfo *f, time_t current_time);
int				process_link_path(t_fileinfo *fileinfo);
t_ull			get_desired_time(t_fileinfo *fileinfo);

/*
** Utils
*/

void			ft_strncpy_nul(char *dest, char *src, size_t len);
char			*ft_strnew_simple(size_t size);
int				print_error(CHR *msg);
int				stat_is_dir(t_stat *buff);
void			ft_strdelif(char **str);
int				file_exists(char *path, t_stat *buff);
int				stat_is_dir(t_stat *buff);
int				file_is_link(char *path);
int				log_ten(t_ull nb);
char			*get_dirent_name(char *path, char *name);
void			ft_memdelif(void **ap);
char			*point_to_last(char *path);
int				file_is_dir(char *path, int follow_link);
char			*get_relative_link_path(char *l_path, char *path);
int				print_malloc_err(void);
int				print_file_doesnt_ex(char *path);
void			ft_lstreverse(t_list **head);
void			int_table_assign_value(int *table, int value, int size);
int				ft_file_exists(char *path);
char			*get_name(t_fileinfo *fileinfo);

/*
** Constructor / destructor
*/

void			init_fileinfo(t_fileinfo *fileinfo);
void			init_ls_data(t_ls_data *ls_data, int argc, char **argv);
t_fileinfo		*new_fileinfo(void);
t_fileinfo		*new_formed_fileinfo(char *path, int follow_link);
void			del_fileinfo(void *content, size_t size);

/*
** List functionalities
*/

void			ft_lst_merge_sort(t_list **head_ref, int (*f)(void*, void*));
void			ft_lst_pushback(t_list **head, t_list *new_el);
int				ft_lst_islast(t_list *cell);
void			map_list(
					t_list *files,
					t_ls_data *dirs,
					void (*f)(t_list*, t_ls_data*));
t_list			*ft_lst_getlast(t_list *head);
t_list			*ft_lstconcat(t_list **dest, t_list *files);

/*
** Compare functions
** Can be found in 'fileinfo_compare_functions.c'
*/

int				fileinfo_name_compare(void *f1, void *f2);
int				fileinfo_time_compare(void *f1, void *f2);

/*
** Colors
*/

char			*rgb_color(int cl, int is_text, char *buff);
char			*get_type_color(t_fileinfo *fileinfo, int can_be_orphan);
char			*get_mode_colors(t_fileinfo *fileinfo);
char			*get_name_color(t_fileinfo *fileinfo);
void			print_color(char *clr);
int				color_is_disabled(t_ls_data *ls_data);

/*
** Simple print helpers
*/

t_list			***new_list(int columns, int h);
int				get_terminal_width(void);
t_list			***split_in_n_columns(t_list *f, int columns, int file_count);
void			set_name_should_be_modified(t_list *file);

#endif
