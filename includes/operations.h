/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:17:49 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 14:50:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "corewar.h"
# define OPC_NBR 16

bool	cw_live(t_cor *core, t_process *proc);
bool	cw_ld(t_cor *core, t_process *proc);
bool	cw_st(t_cor *core, t_process *proc);
bool	cw_add(t_cor *core, t_process *proc);
bool	cw_sub(t_cor *core, t_process *proc);
bool	cw_and(t_cor *core, t_process *proc);
bool	cw_or(t_cor *core, t_process *proc);
bool	cw_xor(t_cor *core, t_process *proc);
bool	cw_zjmp(t_cor *core, t_process *proc);
bool	cw_ldi(t_cor *core, t_process *proc);
bool	cw_sti(t_cor *core, t_process *proc);
bool	cw_fork(t_cor *core, t_process *proc);
bool	cw_lld(t_cor *core, t_process *proc);
bool	cw_lldi(t_cor *core, t_process *proc);
bool	cw_lfork(t_cor *core, t_process *proc);
bool	cw_aff(t_cor *core, t_process *proc);

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
bool					(*g_opctable[OPC_NBR])(t_cor *, t_process *) = {
	&cw_live,
	&cw_ld,
	&cw_st,
	&cw_add,
	&cw_sub,
	&cw_and,
	&cw_or,
	&cw_xor,
	&cw_zjmp,
	&cw_ldi,
	&cw_sti,
	&cw_fork,
	&cw_lld,
	&cw_lldi,
	&cw_lfork,
	&cw_aff
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

bool					g_opparamnb[OPC_NBR] = {
	1,
	2,
	2,
	3,
	3,
	3,
	3,
	3,
	1,
	3,
	3,
	1,
	2,
	3,
	1,
	1
};
bool					g_ocp[OPC_NBR] = {
	false,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	false,
	true,
	true,
	false,
	true,
	true,
	false,
	true
};

#endif
