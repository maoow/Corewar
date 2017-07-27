/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:15 by vkim              #+#    #+#             */
/*   Updated: 2017/07/27 14:46:47 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char			*ft_loading(int ac, char **av, int index, char **load)
{
	int			fd;
	int			ret;
	char		*buff;

	if (!(buff = malloc(5 * sizeof(char))))
			return (*load);
	if (ac < 2 || index >= ac || (fd = open(av[index], O_RDWR)) == -1)
	{
		free(buff);
		return (*load);
	}
	while ((ret = read(fd, buff, 4) > 0))
	{
		buff[4] = '\0';
		if(!(*load = ft_strjoinfree(load, &buff, FIRST)))
		{
			free(buff);
			return (*load);
		}
	}
	free(buff);
	return (*load);
}
