/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:56 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:59:10 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushfront (node *lst, node *new)
{
	if (!lst || !new)
		return ;
	new->prev = lst;
	new->next = lst->next;
	lst->next->prev = new;
	lst->next = new;
}
