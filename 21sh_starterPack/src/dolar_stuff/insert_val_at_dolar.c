/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_val_at_dolar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:57:15 by eterman           #+#    #+#             */
/*   Updated: 2017/01/18 20:16:25 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** Reallocates the memory of dest with inserted value at $dolar. Value is
** len chars from $dolar.
*/

void	insert_val_at_dolar(char **dest, char *value, char *dolar, size_t len)
{
	char	*new_str;
	size_t	env_len;

	env_len = ft_strlen(value);
	if ((new_str = ft_strnew(ft_strlen(*dest) + 1 - len + env_len)) == NULL)
		ft_error_mem();
	ft_strncpy(new_str, *dest, dolar - *dest);
	ft_strcpy(new_str + (dolar - *dest), value);
	ft_strcat(new_str, dolar + len + 1);
	free(*dest);
	*dest = new_str;
}
