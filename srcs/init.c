/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/08/09 19:47:02 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

# include <stdlib.h>
void		init_struct(t_cor *cor)
{
	if (!cor->champs)
	{
		if (!(cor->champs = (t_champ*)malloc(sizeof(*cor->champs))))
			write_error(2);
		cor->champs->name = NULL;
		cor->champs->comment = NULL;
		cor->champs->next = NULL;
	}
	if (!cor->process)
	{
		if (!(cor->process = (t_process*)malloc(sizeof(*cor->process))))
			write_error(2);
		cor->process->next_op = NULL;
		cor->process->next = NULL;
	}
}
