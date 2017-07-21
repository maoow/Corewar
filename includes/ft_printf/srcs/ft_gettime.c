/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:32:52 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/18 16:23:47 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*g_month[12] = {
	"Jan ",
	"Feb ",
	"Mar ",
	"Apr ",
	"May ",
	"Jun ",
	"Jul ",
	"Aug ",
	"Sep ",
	"Oct ",
	"Nov ",
	"Dec "
};

char	*ft_gettime(t_buf_f *buffer, va_list ap, char *format)
{
	t_time	*time;
	char	*str;

	time = NULL;
	if (FLAGS.l)
		time = ft_timeset(time, va_arg(ap, long));
	else
		time = va_arg(ap, t_time *);
	if (FLAGS.sharp)
	{
		ft_buffit(buffer, ft_itoa(time->year), 4);
		ft_buffit(buffer, " ", 1);
	}
	ft_buffit(buffer, g_month[time->month - 1], 4);
	str = ft_itoa(time->day);
	ft_buffit(buffer, "   ", 2 - ft_strlen(str));
	ft_buffit(buffer, str, ft_strlen(str));
	ft_buffit(buffer, " ", 1);
	ft_buffit(buffer, "00", 2 - ft_strlen(ft_itoa(time->hour)));
	ft_buffit(buffer, ft_itoa(time->hour), 2);
	ft_buffit(buffer, ":00", 3 - ft_strlen(ft_itoa(time->minute)));
	ft_buffit(buffer, ft_itoa(time->minute), 2);
	return (format);
}
