/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:31:41 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 00:01:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** environ is a predefined global variable which contains given enviroment
** variables.
*/

extern char		**environ;

static t_list	*create_env_list(void)
{
	t_list	*result;
	t_list	*new_cell;
	int		i;

	result = NULL;
	i = 0;
	while (environ[i])
	{
		new_cell = ft_lstnew((void*)(environ[i]), ft_strlen(environ[i]));
		if (new_cell == NULL)
			ft_error_mem();
		ft_lstadd(&result, new_cell);
		i++;
	}
	return (result);
}

void	env_init(t_sh *sh_data)
{
	sh_data->env.env_list = create_env_list();
	sh_data->env.env_table = NULL;
	sh_data->env.env_is_updated = 0;
}