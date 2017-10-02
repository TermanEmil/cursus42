/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exact_env_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:02:49 by eterman           #+#    #+#             */
/*   Updated: 2017/01/23 22:33:59 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	*get_exact_env_val(char *key, t_sh *sh_data)
{
	char	*env_value;
	size_t	len;

	env_value = get_env_value(key, sh_data, &len);
	if (env_value != NULL && ft_strlen(key) == len)
		return (env_value);
	else
		return (NULL);
}
