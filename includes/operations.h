/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:17:49 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/26 14:18:35 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

bool	live(t_cor *core, t_process *proc);
bool	ld(t_cor *core, t_process *proc);
bool	st(t_cor *core, t_process *proc);
bool	add(t_cor *core, t_process *proc);
bool	sub(t_cor *core, t_process *proc);
bool	and(t_cor *core, t_process *proc);
bool	or(t_cor *core, t_process *proc);
bool	xor(t_cor *core, t_process *proc);
bool	zjmp(t_cor *core, t_process *proc);
bool	ldi(t_cor *core, t_process *proc);
bool	sti(t_cor *core, t_process *proc);
bool	fork(t_cor *core, t_process *proc);
bool	lld(t_cor *core, t_process *proc);
bool	lldi(t_cor *core, t_process *proc);
bool	lfork(t_cor *core, t_process *proc);
bool	aff(t_cor *core, t_process *proc);

size_t					g_optime[OPC_NBR] = {
	10,
	5,
	5,
	10,
	10,
	6,
	6,
	6,
	20,
	25,
	25,
	800,
	10,
	50,
	1000,
	2
};
bool					g_opcarry[OPC_NBR] = {
	false,
	true,
	false,
	true,
	true,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	true,
	true,
	false,
	false,
};
bool					*g_opctable[OPC_NBR] = {
	&live,
	&ld,
	&st,
	&add,
	&sub,
	&and,
	&or,
	&xor,
	&zjmp,
	&ldi,
	&sti,
	&fork,
	&lld,
	&lldi,
	&lfork,
	&aff
};

size_t					g_oplabel[OPC_NBR] = {
4,
4,
0,
0,
0,
4,
4,
4,
2,
2,
2,
2,
4,
2,
2,
0
};