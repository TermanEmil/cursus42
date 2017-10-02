/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_execute_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:20:05 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:51:05 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	error_ft_execve_internal(void)
{
	ft_fprintf(FT_STDERR, "{cyan}minishell: internal error: either commad"
		" or args is NULL in 'ft_execve'\n");
}

void	error_wait_fail(void)
{
	ft_fprintf(FT_STDERR, "{red}minishell: failed to wait for child"
		" process\n");
}

void	error_cant_create_process(void)
{
	ft_fprintf(FT_STDERR, "{red}minishell: couldn't create a"
		" new process: %s\n", strerror(errno));
}

void	error_no_such_filedir(char *path)
{
	ft_fprintf(FT_STDERR, "%s: %s: No such file or directory\n", SH_NAME, path);
}

void	error_permission_denied(char *path)
{
	ft_fprintf(FT_STDERR, "%s: %s: Permission denied\n", SH_NAME, path);
}
