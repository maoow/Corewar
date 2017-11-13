/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:35:07 by starrit           #+#    #+#             */
/*   Updated: 2017/11/13 15:59:42 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	transforme le unsigned char en hexa (int*)
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
	if (!(new[0] = malloc(sizeof(*new[0]))))
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

static void		get_info(bool *start, size_t s, unsigned char buf)
{
	if (s > 148 && buf && buf > 0 && buf < 17)
		*start = true;
}

static size_t	read_loop(unsigned char *buf, char *name, char *comment,
		unsigned char *champion)
{
	static size_t		s = 0;
	static bool			start = false;
	static size_t		size_champ = 0;
	static bool			end = false;

	if (champion == NULL)
	{
		s = 0;
		start = false;
		size_champ = 0;
		return (0);
	}
	get_magic_packet(s, buf, &end);
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

static int		**get_champ(t_cor *cor, unsigned char **champion, int fd,
		int optionnal_id)
{
	unsigned char	buf[2];
	size_t			size_champ;
	char			name[CHAMP_NAME];
	char			comment[COMMENT_NAME];
	int				**ret;

	size_champ = 0;
	while ((read(fd, buf, 1)) > 0)
		size_champ = read_loop(buf, name, comment, *champion);
	read_loop(buf, name, comment, NULL);
	add_champ(cor, name, comment, optionnal_id);
	cor->champs->weight = size_champ;
	(*champion)[size_champ] = '\0';
	close(fd);
	ret = get_hexa(*champion, size_champ);
	free(*champion);
	*champion = NULL;
	return (ret);
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
	return (get_champ(cor, &champion, fd, optionnal_id));
}
