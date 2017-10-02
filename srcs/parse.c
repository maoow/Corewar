/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:35:07 by starrit           #+#    #+#             */
/*   Updated: 2017/10/02 15:53:32 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	transforme le unsigned char *champion binaire en int *champion hexa
*/

static int		**get_hexa(unsigned char *champion, size_t size_champ)
{
	int			**new;
	size_t		i;
	size_t		j;

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
//	recuperer le name et le comment pour remplir la struct champion
static void		get_info(t_cor *cor, bool *start, int s, unsigned char buf)
{
	(void)cor;

	//if (s > 138 && buf && buf > 0 && buf < 17)
	if (s > 148 && buf && buf > 0 && buf < 17)
		*start = true;
}

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
		exit (0);
	}
}

static int		**get_champ(t_cor *cor, unsigned char *champion, int fd, int optionnal_id)
{
	int				s;
	int				ret = 0;
	unsigned char	buf[2];
	size_t			size_champ = 0;
	bool			start = false;
	char			name[CHAMP_NAME];
	char			comment[COMMENT_NAME];
	unsigned char	*magic;
	int				i;

	s = 0;
	magic = ft_memalloc(EXEC_MAGIC_LENGHT + 1);//
	i = 0;
	while ((ret = read(fd, buf, 1)) > 0)
	{
		if (s <= EXEC_MAGIC_LENGHT)
		{
			magic[i] = buf[0];
			i++;
		}
		if (s > 3 && s < CHAMP_NAME)
			name[s - 4] = buf[0];
		if (s >= CHAMP_NAME + 4 && s < COMMENT_NAME)
			comment[s - CHAMP_NAME - 20] = buf[0];
		get_info(cor, &start, s, buf[0]);
		if (start == true)
		{
			champion[size_champ] = buf[0];
			size_champ++;
		}
		s++;
	}
	magic[i] = '\0';
	check_magic_packet(magic);
	add_champ(cor, name, comment, optionnal_id);
	champion[size_champ] = '\0';
	return (get_hexa(champion, size_champ));
}

/*
**	parse un champion en hexa, rempli la structure champ, mais pas process
*/

int				**parse(t_cor *cor, char *av, int optionnal_id)
{
	int				fd;
	unsigned char	*champion;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("crash open");
		exit(0);
	}
	if (!(champion = (unsigned char*)malloc(sizeof(*champion) *
					(CHAMP_MAX_SIZE + 1))))
		write_error(2);
	return (get_champ(cor, champion, fd, optionnal_id));
}
