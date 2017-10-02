/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_compare_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:50:32 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 18:08:52 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcasecmp(CHR *s1, CHR *s2)
{
	int		i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			break ;
		i++;
	}
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
}

int		ft_alphabetize(CHR *s1, CHR *s2)
{
	int	diff;

	diff = ft_strcasecmp(s1, s2);
	if (diff)
		return (diff);
	return (-ft_strcmp(s1, s2));
}

int		fileinfo_name_compare(void *f1, void *f2)
{
	CHR		*s1;
	CHR		*s2;

	s1 = ((t_fileinfo*)f1)->name;
	s2 = ((t_fileinfo*)f2)->name;
	return (ft_alphabetize(s1, s2) < 0);
}

int		fileinfo_time_compare(void *f1, void *f2)
{
	t_ull	t1;
	t_ull	t2;

	t1 = get_desired_time((t_fileinfo*)f1);
	t2 = get_desired_time((t_fileinfo*)f2);
	if (t1 == t2)
		return (fileinfo_name_compare(f1, f2));
	return (t1 > t2);
}
