/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:35:07 by starrit           #+#    #+#             */
/*   Updated: 2017/08/24 15:13:50 by starrit          ###   ########.fr       */
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

	if (s > 138 && buf && buf > 0 && buf < 17)
		*start = true;

}

static int		**get_champ(t_cor *cor, unsigned char *champion, int fd)
{
	int		s;
	int		ret = 0;
	unsigned char	buf[2];
	size_t			size_champ = 0;
	bool			start = false;
	char			name[CHAMP_NAME];
	char			comment[COMMENT_NAME];

	s = 0;
	while ((ret = read(fd, buf, 1)) > 0)
	{
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
	add_champ(cor, name, comment, -1);
	champion[size_champ] = '\0';
	return (get_hexa(champion, size_champ));
}

/*
**	parse un champion en hexa, rempli la structure champ, mais pas process
*/

int				**parse(t_cor *cor, char *av)
{
	int				fd;
	unsigned char	*champion;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("crash open"));
	if (!(champion = (unsigned char*)malloc(sizeof(*champion) * (CHAMP_MAX_SIZE + 1))))
		write_error(2);
	return (get_champ(cor, champion, fd));
}
