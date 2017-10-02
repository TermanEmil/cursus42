/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:46:47 by eterman           #+#    #+#             */
/*   Updated: 2017/04/02 17:51:07 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termcap.h>
# include <termios.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PRJ_NAME	"ft_select"
# define FD_WR		2

/*
** ft_strlen(CURSOR_MATCH) <= ft_strlen(CURSOR_FRONT)
*/

# define CURSOR_FRONT	">"
# define CURSOR_END		"<"
# define CURSOR_MATCH	"*"

# define EOC "\033[0m"
# define REVERSE_VIDEO "\033[7m"
# define UNDERLINE "\033[4m"

# define UNDERLINE_FLAG	(1 << 0)
# define SELECT_FLAG (1 << 1)

# define ARROW_UP		"\033[A"
# define ARROW_DOWN		"\033[B"
# define ARROW_LEFT		"\033[D"
# define ARROW_RIGHT	"\033[C"
# define DEL_KEY		"\033[3~"
# define BACKSPACE		"\x7f"
# define CTRL_A			"\01"
# define CTR_F			"\06"
# define ALT_ENTER		"\033\012"
# define ALT_DEL		"\033[3;3~"
# define SHIFT_TAB		"\033[Z"
# define SHIFT_DEL		"\033[3;2~"

typedef struct termios	t_termios;

typedef struct	s_option
{
	char		*value;
	int			is_selected;
	int			matches;
}				t_option;

typedef struct	s_select
{
	t_termios	old_term;
	t_list		*options;
	int			cursor_pos;
	int			win_width;
	int			win_height;
	int			col_len;
	char		find_input[50];
	int			is_in_find_mode;
	int			must_refresh;
}				t_select;

typedef int	(t_key_cmd)(t_select *data);

/*
** Errors
*/

/*
** Error_helpers
*/

void			ft_err_mem(int exit_program);
void			ft_fatal(const char *msg);
void			ft_err_mem(int exit_program);
int				ft_proj_err(const char *msg, int exit_program);

/*
** Constructors
*/

void			init_select_data(t_select *data, int argc, char **argv);
void			setup_terminal(void);

/*
** Signals
*/

void			listen_to_signals(void);

/*
** "Global" data
*/

t_select		*get_select_data(t_select *new_data);
const t_dex		*get_dex(void);

/*
** Termcap
*/

void			ft_tputs(char *attr_name);
void			full_screen(int yes);
void			cursor_on(int yes);
void			ft_clear_screen(void);
void			echo_off(void);
void			term_restore(void);
void			cursor_goto(int x, int y);

/*
** Print
*/

int				tputs_putchar(int c);
void			print_options(t_select *data);
void			refresh_output();
void			print_with_effects(char *text, int flag);
void			rewrite_option(int option_index, int last_len, int effects);
void			print_selected(t_list *options, int is_first);
void			print_help_text(int fd);

/*
** Key commands
*/

int				process_input(t_select *data);
int				key_cmd_up(t_select *data);
int				key_cmd_down(t_select *data);
int				key_cmd_left(t_select *data);
int				key_cmd_right(t_select *data);
int				key_cmd_esc(t_select *data);
int				key_cmd_space(t_select *data);
int				key_cmd_del(t_select *data);
int				key_cmd_enter(t_select *data);
int				key_cmd_ctrl_a(t_select *data);
int				key_enter_find_mode(t_select *data);
int				key_cmd_bakspace(t_select *data);
int				key_cmd_alt_enter(t_select *data);
int				delete_selected(t_select *data);
int				show_help(t_select *data);

/*
** Find input
*/

void			add_char_to_find_input(t_select *data, char c);
void			update_find(t_select *data);

/*
** Utilities
*/

t_option		*get_option(int option_index);
int				get_effects(int option_index, int is_cursored);
void			select_matches(t_list *options);
void			delete_option(int option_index);

/*
** Other
*/

void			update_col_len(t_select *data);
int				get_coords(int *x, int *y, int index, t_select *data);
int				goto_option(int option_index, t_select *data);
void			change_select_value(t_list *options, int to_true);
void			change_cursor_pos(t_select *data, int x, int y);
char			*get_color(char *arg);

#endif
