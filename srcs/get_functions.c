/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:06:46 by starrit           #+#    #+#             */
/*   Updated: 2017/09/02 18:15:43 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_process_color(t_cor *cor, t_process *proc)
{
	int			champ_id;
	t_champ		*champ;

	champ_id = proc->registres[0];
	champ = cor->champs;
	while (champ)
	{
		if ((int)champ->ID == champ_id)
			return (champ->color);
		champ = champ->next;
	}
	return (0);
}
