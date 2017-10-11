/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:35:07 by starrit           #+#    #+#             */
/*   Updated: 2017/10/11 14:39:16 by starrit          ###   ########.fr       */
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
	if (!(new = malloc(sizeof(*new) * 2)))
		write_error(2);
	if (!(new[0] = malloc(sizeof(*new[0] * 1))))
		write_error(2);
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
static void		get_info(bool *start, size_t s, unsigned char buf)
{
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
		exit(0);
	}
}

static void		get_magic_packet(size_t s, unsigned char *buf)
{
	static size_t			i = 0;
	static bool				end = false;
	static unsigned char	*magic = NULL;

	if (!magic)
		if (!(magic = ft_memalloc(EXEC_MAGIC_LENGHT + 1)))
			write_error(2);
	if (s <= EXEC_MAGIC_LENGHT)
	{
		magic[i] = buf[0];
		i++;
	}
	else if (!end)
	{
		magic[i] = '\0';
		check_magic_packet(magic);
		end = true;
	}
}

static size_t	read_loop(unsigned char *buf, char *name, char *comment,
		unsigned char *champion)
{
	static size_t		s = 0;
	static bool			start = false;
	static size_t		size_champ = 0;

	if (champion == NULL)
	{
		s = 0;
		start = false;
		size_champ = 0;
		return (0);
	}
	get_magic_packet(s, buf);
	if (s > 3 && s < CHAMP_NAME)
		name[s - 4] = buf[0];
	if (s >= CHAMP_NAME + 4 && s < COMMENT_NAME)
		comment[s - CHAMP_NAME - 20] = buf[0];
	get_info(&start, s, buf[0]);
	if (start)
	{
		champion[size_champ] = buf[0];
		size_champ++;
	}
	s++;
	return (size_champ);
}

static int		**get_champ(t_cor *cor, unsigned char *champion, int fd,
		int optionnal_id)
{
	unsigned char	buf[2];
	size_t			size_champ;
	char			name[CHAMP_NAME];
	char			comment[COMMENT_NAME];

	size_champ = 0;
	while ((read(fd, buf, 1)) > 0)
		size_champ = read_loop(buf, name, comment, champion);
	read_loop(buf, name, comment, NULL);
	add_champ(cor, name, comment, optionnal_id);
	cor->champs->weight = size_champ;
	champion[size_champ] = '\0';
	close(fd);
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
