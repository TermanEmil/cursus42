/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:24:55 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:55:55 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	execute_cmd(char **args, t_sh *sh_data)
{
	t_cmd_fun	cmd_fun;

	if (args == NULL || args[0] == NULL || args[0][0] == 0)
		return ;
	if (execute_first_arg(args, sh_data) == 0)
		return ;
	if ((cmd_fun = find_function_in_dex(args[0], sh_data)) != NULL)
		cmd_fun(args, sh_data);
	else
	{
		if (execute_from_path(args, sh_data) != 0)
		{
			if (ft_strchr(args[0], '/'))
				error_no_such_filedir(args[0]);
			else	
				ft_fprintf(FT_STDERR, "%s: command not found\n", args[0]);
		}
	}
}
