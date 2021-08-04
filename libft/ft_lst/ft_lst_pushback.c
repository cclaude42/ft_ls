/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:59:07 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback (node *lst, node *new)
{
	if (!lst || !new)
		return ;
	new->prev = lst->prev;
	new->next = lst;
	lst->prev->next = new;
	lst->prev = new;
}
