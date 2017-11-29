/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:58:10 by starrit           #+#    #+#             */
/*   Updated: 2017/11/28 12:53:55 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Assemble l'hexa du magic paquet pour avoir un int (cf get_ram dans
**	ramfunctions.c) et le compare au define magic packet
*/

static void		check_magic_packet(unsigned char *magic)
{
	size_t		i;
	int			res;

	i = 0;
	res = 0;
	while (i <= EXEC_MAGIC_LENGHT)
	{
		res = res + magic[i];
		if (i < EXEC_MAGIC_LENGHT)
			res = res * 256;
		i++;
	}
	if (res != MAGIC_PACKET)
	{
		ft_putendl("Wrong Magic Packet");
		exit(0);
	}
}

void			get_magic_packet(size_t s, unsigned char *buf, bool *end)
{
	static size_t			i = 0;
	static unsigned char	*magic = NULL;

	if (s <= EXEC_MAGIC_LENGHT)
		*end = false;
	if (!magic && !*end)
	{
		if (!(magic = ft_memalloc(EXEC_MAGIC_LENGHT + 1)))
			write_error(2);
	}
	if (s <= EXEC_MAGIC_LENGHT)
	{
		magic[i] = buf[0];
		i++;
	}
	else if (!*end)
	{
		magic[i] = '\0';
		check_magic_packet(magic);
		*end = true;
		free(magic);
		magic = NULL;
		i = 0;
	}
}
