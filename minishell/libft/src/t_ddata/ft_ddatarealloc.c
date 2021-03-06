/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddatarealloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:28:06 by eterman           #+#    #+#             */
/*   Updated: 2017/01/19 16:53:06 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DSIZE ddata->size

int			ft_ddatarealloc(t_ddata *ddata, size_t required_size)
{
	void	*new_content;
	size_t	delta;
	size_t	n;
	size_t	new_size;

	if (ddata == NULL)
		return (-1);
	if (required_size > DSIZE)
	{
		delta = required_size - DSIZE;
		n = (delta % ddata->d_size != 0) + delta / ddata->d_size;
		new_size = DSIZE + n * ddata->d_size;
		if ((new_content = malloc(new_size + 1)) == NULL)
			return (ENOMEM);
		ft_bzero(new_content, new_size + 1);
		if (ddata->content != NULL)
		{
			ft_memcpy(new_content, ddata->content, DSIZE);
			free(ddata->content);
		}
		ddata->content = new_content;
		ddata->size = new_size;
	}
	return (0);
}
