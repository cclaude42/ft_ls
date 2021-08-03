/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:57:20 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 21:26:22 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rev (node *lst)
{
	node	*current;
	node	*tmp;

	current = lst->next;
	while (current != lst)
	{
		tmp = current->next;
		current->next = current->prev;
		current->prev = tmp;
		current = current->prev;
	}
	tmp = lst->next;
	lst->next = lst->prev;
	lst->prev = tmp;
}
