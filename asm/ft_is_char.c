/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:17:06 by vkim              #+#    #+#             */
/*   Updated: 2017/11/03 11:27:37 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_is_lblchr(char c)
{
	if (!ft_strchr(LABEL_CHARS, c) && (c < '0' || c > '9'))
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}

int				ft_is_lbl_o_dgt(char c)
{
	if ((c < '0' || c > '9') && c != ':')
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}

int				ft_is_lex(char c)
{
	if (!ft_is_lblchr(c) && !ft_is_lbl_o_dgt(c) && c != ',' && c != ' '
		&& c != '\t' && c != '%' && c != '\0')
		return (0);
	return (1);
}

int				ft_is_sep(char c)
{
	if (c != ' ' && c != '\t' && c != ',')
		return (0);
	return (1);
}
