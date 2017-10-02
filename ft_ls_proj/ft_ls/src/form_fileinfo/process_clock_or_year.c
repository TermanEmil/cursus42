/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clock_or_year.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:12:06 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:33:06 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Sometimes, if the file is 'from' future or it's older than 6 months, it's
** not displayed the clock but the year.
** If I want to see other times, like last_access_time, I must change
** fileinfo->time_parts.which_time = TIME_LAST_ACCESS (see ft_ls.h).
*/

/*
** six months in seconds. Source google calculator.
*/

#define SIX_MONTHS 15768000

static int		is_future(t_ull t, t_ull current_time)
{
	return (t > current_time);
}

static int		is_older_than_six_months(t_ull t, t_ull current_time)
{
	return (!is_future(t + SIX_MONTHS, current_time));
}

static int		is_recent(t_ull t, t_ull current_time)
{
	if (is_future(t, current_time) || is_older_than_six_months(t, current_time))
		return (0);
	return (1);
}

void			process_clock_or_year(t_fileinfo *fileinfo, time_t current_time)
{
	t_ull	t;
	char	*target;

	t = get_desired_time(fileinfo);
	if (is_recent(t, current_time))
		target = fileinfo->time_parts.clock;
	else
		target = fileinfo->time_parts.year;
	ft_strcpy(fileinfo->time_parts.clock_or_year, target);
}
