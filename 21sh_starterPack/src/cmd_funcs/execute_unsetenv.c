/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 00:05:50 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:27:27 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int	single_unsetenv(char *arg, t_sh *sh_data)
{
	t_list	*prev;
	t_list	*env_list;

	if (ft_strchr(arg, '='))
	{
		ft_fprintf(STDERR, "%s: setenv: `%s': not a valid identifier\n",
			SH_NAME, arg);
		return (1);
	}
	prev = NULL;
	env_list = sh_data->env.env_list;
	while (env_list)
	{
		if (env_cmp_key(LSTR(env_list), arg))
		{
			ft_lstrm_with_prev(&(sh_data->env.env_list), env_list, prev);
			sh_data->env.env_is_updated = 0;
			return (0);
		}
		prev = env_list;
		env_list = LNEXT(env_list);
	}
	return (0);
}

void	execute_unsetenv(char **args, t_sh *sh_data)
{
	args++;
	while (*args)
	{
		single_unsetenv(*args, sh_data);
		args++;
	}
}
