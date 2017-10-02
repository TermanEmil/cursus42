/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_first_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:15:19 by eterman           #+#    #+#             */
/*   Updated: 2017/01/25 15:37:39 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		execute_first_arg(char **args, t_sh *sh_data)
{
	t_stat buff;

	if (ft_strchr("./", args[0][0]) == NULL)
		return (-1);
	if (stat(args[0], &buff) < 0)
		return (-1);
	if (S_ISDIR(buff.st_mode))
	{
		ft_fprintf(FT_STDERR, "%s: %s: Is a directory\n", SH_NAME, args[0]);
		return (0);
	}
	if (access(args[0], F_OK) != 0)
		return (-1);
	if (access(args[0], X_OK) != 0)
	{
		error_permission_denied(args[0]);
		return (0);
	}
	ft_execve(args[0], args, sh_data);
	return (0);
}
