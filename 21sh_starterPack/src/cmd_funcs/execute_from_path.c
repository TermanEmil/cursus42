/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_from_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:25:34 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:25:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int		can_execve(char *f_path)
{
	t_stat	buff;

	if (access(f_path, F_OK | X_OK) != 0)
	{
		ft_fprintf(STDERR, "%s: %s: Permission denied\n", SH_NAME, f_path);
		return (-1);
	}
	if (stat(f_path, &buff) < 0)
		return (0);
	if (S_ISDIR(buff.st_mode))
		return (0);
	return (1);
}

static int		try_a_path(char *path, char **args, t_sh *sh_data)
{
	DIR			*dir_path;
	t_dirent	*buff;
	char		*fullpath;
	int			ret;

	if ((dir_path = opendir(path)) == NULL)
		return (-1);
	while ((buff = readdir(dir_path)) != NULL)
		if (ft_strequ(buff->d_name, args[0]))
		{
			if ((fullpath = ft_strmegajoin(3, path, "/", buff->d_name)) == NULL)
				ft_error_mem();
			if ((ret = can_execve(fullpath)) > 0)
				ft_execve(fullpath, args, sh_data);
			free(fullpath);
			if (ret != 0)
			{
				closedir(dir_path);
				return (0);
			}
		}
	closedir(dir_path);
	return (-1);
}

/*
** Tries every program in every path in PATH.
*/

int				execute_from_path(char **args, t_sh *sh_data)
{
	size_t	len;
	char	*path_value;
	char	**paths;
	int		i;

	path_value = get_env_value("PATH", sh_data, &len);
	if (path_value == NULL || len != ft_strlen("PATH"))
		return (-1);
	if ((paths = ft_strsplit(path_value, (IS_WINDOWS) ? ';' : ':')) == NULL)
		ft_error_mem();
	i = 0;
	while (paths[i])
	{
		if (try_a_path(paths[i], args, sh_data) == 0)
			return (0);
		i++;
	}
	ft_free_bidimens(paths);
	return (-1);
}
