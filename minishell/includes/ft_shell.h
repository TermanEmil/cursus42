/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:35 by eterman           #+#    #+#             */
/*   Updated: 2017/01/12 18:23:45 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_H
# define FT_SHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/stat.h>

# define SHELL_DELIMS	" \t\n"
# define SH_NAME		"minishell"

# ifdef _WIN32
#  define IS_WINDOWS 1
# else
#  define IS_WINDOWS 0
# endif

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct		s_env
{
	t_list			*env_list;
	char			**env_table;
	int				env_is_updated;
}					t_env;

typedef struct		s_current_data
{
	char			*raw_input;
}					t_current_data;

typedef struct		s_sh
{
	t_env			env;
	t_list			*cmd_history;
	t_list			*cmd_dex;
	t_current_data	current_data;
}					t_sh;

typedef void (*t_cmd_fun)(char **args, t_sh *sh_data);

typedef struct		s_cmd_key
{
	char			*cmd;
	t_cmd_fun		key;
}					t_cmd_key;

/*
** Utils
*/

int			its_true_char(char *context, char *c_addr);
char		*ft_str3concat(char **dest, char *s1, char *s2);
void		ft_lstrm_with_prev(t_list **head, t_list *target, t_list *prev);
char		*getcwd_alloc(void);

/*
** Errors
*/

void		ft_error_mem(void);
void		ft_big_error(const char *msg);
void		*error_intern_env_invalid(char *env_var);
void		error_ft_execve_internal(void);
void		error_wait_fail(void);
void		error_cant_create_process(void);
void		error_no_such_filedir(char *path);
void		error_permission_denied(char *path);
void		error_env_var_not_set(char *env_name);

/*
** Commands
*/

void		execute_echo(char **args, t_sh *sh_data);
void		execute_exit(char **args, t_sh *sh_data);
void		execute_setenv(char **args, t_sh *sh_data);
void		execute_env(char **args, t_sh *sh_data);
void		execute_unsetenv(char **args, t_sh *sh_data);
void		execute_cd(char **args, t_sh *sh_data);
int			execute_from_path(char **args, t_sh *sh_data);
int			execute_first_arg(char **args, t_sh *sh_data);

/*
** execute_cmd helpers
** in src/cmd_funcs/cmd_execute_helpers
*/

void		ft_execve(char *cmd, char **args, t_sh *sh_data);
t_cmd_fun 	find_function_in_dex(char *cmd_name, t_sh *sh_data);
void		execute_cmd(char **args, t_sh *sh_data);

/*
** Constructors
*/

void		env_init(t_sh *sh_data);
void		init_cmd_dex(t_sh *sh_data);

/*
** Destructors
*/

void		del_strlist_cell(void *data, size_t size);
void		env_destroy(t_sh *sh_data);

/*
** Get input stuff
*/

char		*read_cmd(void);
char		**extract_all_arguments(char *cmd);
int			ft_rawgetch(void);

/*
** Enviroment stuff
*/

char		**get_env_table(t_sh *sh_data);
char		*get_env_value(char *key, t_sh *sh_data, size_t *len);
int			env_cmp_key(char *full_env_val, char *key);
int			env_replace(char *key, char *new_val, t_sh *sh_data);
char		*get_exact_env_val(char *key, t_sh *sh_data);
void		env_add_value(char *value, t_sh *sh_data);
void		force_env_replace(char *env_name, char *env_value, t_sh *sh_data);

/*
** Dolar stuff
*/

void		process_dolar_values(char **str_addr, t_sh *sh_data);
void		insert_val_at_dolar(char **dest, char *val, char *dlr, size_t len);
int			process_dolar_envir(char **str_addr, char **dolar, t_sh *sh_data);
int			process_dolar_null(char *dolar);

#endif