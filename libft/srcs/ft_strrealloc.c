/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:30:48 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/08 18:32:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *str, int size)
{
	char	*dst;
	int		i;

	i = 0;
	if (str == NULL)
	{
		dst = (char *)malloc((size + 1) * sizeof(*dst));
		return (dst);
	}
	if ((dst = (char *)malloc((ft_strlen(str) + size + 1) * sizeof(*dst))) ==
			NULL)
		return (NULL);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	free(str);
	return (dst);
}
