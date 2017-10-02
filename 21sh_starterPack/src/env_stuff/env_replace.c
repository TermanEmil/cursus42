/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 00:06:36 by eterman           #+#    #+#             */
/*   Updated: 2017/01/22 00:28:16 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** key must be of the following format: key\0value. I change the '\0' with '='.
** After it successfuly changes the env list, it sets 'updated = 0'.
*/

int		env_replace(char *key, char *new_val, t_sh *sh_data)
{
	t_list	*envs;
	char	*new_env;

	if (key == NULL)
		return (-1);
	envs = sh_data->env.env_list;
	while (envs)
	{
		if (env_cmp_key(LSTR(envs), key))
		{
			free(envs->content);
			new_env = ft_strnew(ft_strlen(key) + ft_strlen(new_val) + 1);
			if (new_env == NULL)
				ft_error_mem();
			ft_strcpy(new_env, key);
			ft_strcat(new_env, "=");
			ft_strcat(new_env, new_val);
			envs->content = (void*)new_env;
			sh_data->env.env_is_updated = 0;
			return (0);
		}
		envs = envs->next;
	}
	return (-2);
}
