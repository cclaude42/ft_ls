/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:16 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:59:00 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_iter (node *lst, void (*f)(void *))
{
	node	*current;

	if (!lst || !f)
		return ;
	current = lst->next;
	while (current != lst)
	{
		f(current->data);
		current = current->next;
	}
}
