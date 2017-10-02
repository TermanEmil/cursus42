/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:24:26 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:27:52 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static void		print_cd_errors(char *path)
{
	t_stat	buff;

	if (stat(path, &buff) < 0)
		error_no_such_filedir(path);
	else if (!S_ISDIR(buff.st_mode))
		ft_fprintf(STDERR, "%s: cd: %s: Not a directory\n", SH_NAME, path);
	else if (access(path, X_OK) != 0)
		error_permission_denied(path);
}

static int		cd_to_dir(char *dir, t_sh *sh_data)
{
	char	*oldpwd;
	char	*newpwd;

	oldpwd = getcwd_alloc();
	if (chdir(dir) == 0)
	{
		newpwd = getcwd_alloc();
		force_env_replace("OLDPWD", oldpwd, sh_data);
		force_env_replace("PWD", newpwd, sh_data);
		return (0);
	}
	else
	{
		print_cd_errors(dir);
		return (1);
	}
}

static char		*get_home_dir(t_sh *sh_data)
{
	struct passwd	*buff;
	char			*value;

	if ((value = get_exact_env_val("HOME", sh_data)) != NULL)
		return (value);
	if ((buff = (struct passwd*)malloc(sizeof(struct passwd))) == NULL)
		ft_error_mem();
	if ((buff = getpwuid(getuid())) == NULL)
	{
		free(buff);
		ft_fprintf(STDERR, "%s: cd: Can't find HOME directory\n");
		return (NULL);
	}
	value = buff->pw_name;
	free(buff);
	return (value);
}

void		execute_cd(char **args, t_sh *sh_data)
{
	char	*value;

	if (args[1] == NULL)
	{
		if ((value = get_home_dir(sh_data)) != NULL)
			cd_to_dir(value, sh_data);
	}
	else if (ft_strequ(args[1], "-"))
	{
		if ((value = get_exact_env_val("OLDPWD", sh_data)) == NULL)
			return (error_env_var_not_set("OLDPWD"));
		cd_to_dir(value, sh_data);
	}
	else
		cd_to_dir(args[1], sh_data);
}
