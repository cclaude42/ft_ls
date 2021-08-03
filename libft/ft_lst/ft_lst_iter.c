/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:16 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 18:03:05 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_iter (node *nil, void (*f)(void *))
{
	node	*current;

	if (!nil || !f)
		return ;
	current = nil->next;
	while (current != nil)
	{
		f(current->data);
		current = current->next;
	}
}
