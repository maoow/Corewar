/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:31:22 by vkim              #+#    #+#             */
/*   Updated: 2017/08/04 16:00:46 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_mem_len(t_asm *t_val_asm)
{
	// Si % 8 == 0 ajustement = 8 pour faire 8 - 8
	len_name = 4 + PROG_NAME_LENGTH + 8 - ((PROG_NAME_LENGTH + 4) % 8)
		= 4 + 128 + 4 = 136 (17 oct / 8.5 lignes)
	len_comment = 3 + 5 + COMMENT_LENGHT + 8 - (COMMENT_LENGTH % 8)
	+ operations
}
