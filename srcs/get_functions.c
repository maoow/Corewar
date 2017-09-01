/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:06:46 by starrit           #+#    #+#             */
/*   Updated: 2017/09/01 16:07:14 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_process_color(t_cor *cor, t_process *proc)
{
	size_t		champ_id;
	t_champ		*champ;

	champ_id = proc->registres[0];
	champ = cor->champs;
	while (champ)
	{
		if (champ->ID == champ_id)
			return (champ->color);
		champ = champ->next;
	}
	return (0);
}
