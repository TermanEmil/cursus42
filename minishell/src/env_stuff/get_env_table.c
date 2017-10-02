/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:15:53 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 11:42:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Creates an array of strings from the list (the list has char* content).
*/

static void	make_table_from_list(char **dest, t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		dest[i] = LSTR(list);
		list = list->next;
		i++;
	}
	dest[i] = NULL;
}

static void	update_env_table(t_sh *sh_data)
{
	char	**env_table;
	size_t	size;

	env_table = sh_data->env.env_table;
	if (sh_data->env.env_table != NULL)
		free(env_table);
	size = ft_lstlen(sh_data->env.env_list);
	if ((env_table = (char**)malloc(sizeof(char*) * size + 100)) == NULL)
		ft_error_mem();
	make_table_from_list(env_table, sh_data->env.env_list);
	sh_data->env.env_table = env_table;
	sh_data->env.env_is_updated = 1;
}

/*
** Updates the enviroment table (the array of enviroment strings) if
** necessary.
*/

char	**get_env_table(t_sh *sh_data)
{
	if (!(sh_data->env.env_is_updated))
		update_env_table(sh_data);
	return (sh_data->env.env_table);
}
