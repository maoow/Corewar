/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:53:15 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/08 18:33:35 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstreplace(t_list **lst, t_list *new, int place)
{
	t_list	*tmp;
	t_list	*prev;

	if (place == 0)
	{
		free((*lst)->content);
		free(*lst);
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (place)
		{
			prev = tmp;
			tmp = tmp->next;
			place--;
		}
		prev->next = new;
		new->next = tmp->next;
		free(tmp->content);
		free(tmp);
	}
}
