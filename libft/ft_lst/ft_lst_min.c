/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:12:12 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 20:21:54 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node	*ft_lst_min (node *lst, int (*cmp)(void *, void *))
{
	node	*current;
	node	*min;

	current = lst->next;
	min = current;
	while (current != lst)
	{
		if (cmp(min->data, current->data) > 0)
			min = current;
		current = current->next;
	}
	return (min);
}
