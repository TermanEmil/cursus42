/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:59:03 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:20:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	execute_echo(char **args, t_sh *sh_data)
{
	if (!ft_strequ(args[0], "echo"))
	{
		ft_fprintf(FT_STDERR, "{cyan}minishell: internal error: "
			"din't pass correctly the 'echo' args (first arg isn't 'echo'\n");
		exit(EXIT_FAILURE);	
	}
	ft_execve("/bin/echo", args, sh_data);
}
