/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:55:14 by eterman           #+#    #+#             */
/*   Updated: 2017/01/22 00:26:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	execute_env(char **args, t_sh *sh_data)
{
	char	**envs;

	(void)args;
	envs = get_env_table(sh_data);
	while (*envs)
	{
		ft_putstr(*envs);
		ft_putchar('\n');
		envs++;
	}
}
