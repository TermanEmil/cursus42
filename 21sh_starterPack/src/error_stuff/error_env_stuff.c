/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_env_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:39:57 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:29:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	*error_intern_env_invalid(char *env_var)
{
	ft_fprintf(STDERR, "{cyan}minishell: internal error: "
		"invalid format for env variable %s\n", env_var);
	return (NULL);
}

void	error_env_var_not_set(char *env_name)
{
	ft_fprintf(STDERR, "%s: cd: %s not set\n", SH_NAME, env_name);
}
