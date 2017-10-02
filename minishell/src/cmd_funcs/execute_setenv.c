/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:59:34 by eterman           #+#    #+#             */
/*   Updated: 2017/01/22 00:30:04 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Adds at the end of the list.
*/

void		env_add_value(char *value, t_sh *sh_data)
{
	t_list	*new_env;

	if ((new_env = ft_lstnew((void*)value, ft_strlen(value))) == NULL)
		ft_error_mem();
	ft_lstadd(&(sh_data->env.env_list), new_env);
	sh_data->env.env_is_updated = 0;
}

/*
** For example: VAR!@#$ is invalid.
*/

static int	env_key_is_valid(char *key, int len)
{
	int		i;

	if (!ft_isalpha(*key))
		return (0);
	i = 1;
	while (i < len)
	{
		if (!ft_isalnum(key[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	single_setenv(char *arg, t_sh *sh_data)
{
	char	*eq;
	char	*env_value;
	size_t	len;
	char	*dub_arg;

	if ((eq = ft_strchr(arg, '=')) == NULL)
		return ;
	if (eq == arg || !env_key_is_valid(arg, eq - arg))
		ft_fprintf(FT_STDERR, "%s: setenv: `%s': not a valid identifier\n",
			SH_NAME, arg);
	else
	{
		env_value = get_env_value(arg, sh_data, &len);
		if ((dub_arg = ft_strdup(arg)) == NULL)
			ft_error_mem();
		*eq = 0;
		if (env_value != NULL && ft_strlen(arg) == len)
			env_replace(arg, arg + ft_strlen(arg) + 1, sh_data);
		else
		{
			*eq = '=';
			env_add_value(arg, sh_data);
		}
	}
}

void		execute_setenv(char **args, t_sh *sh_data)
{
	args++;
	while (*args)
	{
		single_setenv(*args, sh_data);
		args++;
	}
}
