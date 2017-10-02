/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmp_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:59:22 by eterman           #+#    #+#             */
/*   Updated: 2017/01/22 00:30:42 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		env_cmp_key(char *full_env_val, char *key)
{
	size_t	len;

	if (key == NULL || full_env_val == NULL)
		return (0);
	len = ft_strlen(key);
	return (ft_strnequ(full_env_val, key, len) && full_env_val[len] == '=');
}
