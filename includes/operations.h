/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:17:49 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/20 13:35:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# define OPC_NBR 16
# include "corewar.h"

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

#endif
