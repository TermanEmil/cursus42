/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:30:55 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 19:57:15 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static size_t	lentochar(char *str, char c)
{
	char	*addr;

	if (str == NULL)
		return (-1);
	addr = ft_strchr(str, c);
	if (addr == NULL)
		return (-1);
	return (addr - str);
}

/*
** That cast is just to silence the warnings.
*/

static char		*best_key(char *key, t_list *env_list, size_t *len)
{
	size_t	this_len;
	size_t	another_len;
	char	*another_match;

	while (env_list)
	{
		if ((this_len = lentochar(LSTR(env_list), '=')) == (unsigned)-1)
			return ((char*)error_intern_env_invalid(LSTR(env_list)));
		else if (ft_strnequ(key, LSTR(env_list), this_len))
		{
			another_match = best_key(key, LNEXT(env_list), &another_len);
			if (another_match != NULL && this_len < another_len)
			{
				*len = another_len;
				return (another_match);
			}
			else
			{
				*len = this_len;
				return (LSTR(env_list) + this_len + 1);
			}
		}
		env_list = LNEXT(env_list);
	}
	return (NULL);
}

/*
** len is the length of the key: $PATHkek -- *len == 4
*/

char			*get_env_value(char *key, t_sh *sh_data, size_t *len)
{
	return (best_key(key, sh_data->env.env_list, len));
}
