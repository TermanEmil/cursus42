/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:59:03 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:24:45 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	execute_echo(char **args, t_sh *sh_data)
{
	if (!ft_strequ(args[0], "echo"))
	{
		ft_fprintf(STDERR, "{cyan}minishell: internal error: "
			"din't pass correctly the 'echo' args (first arg isn't 'echo'\n");
		exit(EXIT_FAILURE);	
	}
	ft_execve("/bin/echo", args, sh_data);
}
