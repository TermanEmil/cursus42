/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:44:47 by eterman           #+#    #+#             */
/*   Updated: 2017/05/29 18:39:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*dex_new(void *key, void *value)
{
	t_dict	*result;
	t_list	*list_rs;

	if ((result = (t_dict*)malloc(sizeof(t_dict))) == NULL)
		return (NULL);
	result->key = key;
	result->value = value;
	list_rs = (t_list*)malloc(sizeof(t_list));
	list_rs->content_size = sizeof(t_dict);
	list_rs->content = result;
	list_rs->next = NULL;
	return (list_rs);
}
