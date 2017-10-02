/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:58:27 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:26:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

extern pid_t	g_current_process;

static int	its_child_process(pid_t father)
{
	return (father == 0);
}

static int	its_main_process(pid_t father)
{
	return (father > 0);
}

/*
** father will be 0 in child process and greater than it, in father process.
*/

void	ft_execve(char *cmd, char **args, t_sh *sh_data)
{
	pid_t	father;
	int		status;

	if (cmd == NULL || args == NULL)
	{
		error_ft_execve_internal();
		return ;	
	}
	errno = 0;
	father = fork();
	if (its_child_process(father))
	{
		execve(cmd, args, get_env_table(sh_data));
		ft_fprintf(STDERR, "{red}%s: %s: Invalid command\n", SH_NAME, cmd);
	}
	else if (its_main_process(father))
	{
		g_current_process = 1;
		if (wait(&status) < 0)
			error_wait_fail();
		g_current_process = 0;
	}
	else
		error_cant_create_process();
}
