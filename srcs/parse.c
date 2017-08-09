/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:35:07 by starrit           #+#    #+#             */
/*   Updated: 2017/08/09 19:38:21 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

/*
**	transforme le unsigned char *champion binaire en int *champion hexa
*/
static int		**get_hexa(unsigned char *champion, size_t size_champ)
{
	int	**new;
	int	i;
	int j;

	i = 0;
	j = 0;
	new = malloc(sizeof(*new) * 2);//
	new[0] = malloc(sizeof(*new[0] * 1));//
	new[0][0] = (int)size_champ;
	if (!(new[1] = (int*)malloc(sizeof(*new[1]) * (size_champ + 1))))
		write_error(2);
	while (i < size_champ)
	{
		new[1][j] = champion[i];
		j++;
		i++;
	}
	return (new);
}

//	changer 138 par la formule exacte (voir asm)
static void		get_info(t_cor *cor, bool *start, int s, unsigned char buf)
{
	(void)cor;
	
	if (s > 138 && buf && buf > 0 && buf < 17)
		*start = true;
}

static int		**get_champ(t_cor *cor, char *av, unsigned char *champion, int fd)
{
	int		s;
	int		ret = 0;
	unsigned char	buf[2];
	size_t			size_champ = 0;
	bool			start = false;

	s = 0;
	while ((ret = read(fd, buf, 1)) > 0)
	{
		get_info(cor, &start, s, buf[0]);
		if (start == true)
		{
			champion[size_champ] = buf[0];
			size_champ++;
		}
		s++;
	}
	champion[size_champ] = '\0';
	return (get_hexa(champion, size_champ));
}

/*
**	parse un champion en hexa et rempli sa struct champ
**	rempli sa struct process
*/

// a faire : 	remplir les 2 struct

int				**parse(t_cor *cor, char *av)
{
	int				fd;
	unsigned char	*champion;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(printf("crash open"));//ft_printf
	if (!(champion = (unsigned char*)malloc(sizeof(*champion) * (CHAMP_MAX_SIZE + 1))))
		write_error(2);
	init_struct(cor);
	return (get_champ(cor, av, champion, fd));
}
