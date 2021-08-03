/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:57:20 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 20:31:07 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node	*ft_lst_sort (node *lst, int (*cmp)(void *, void *))
{
	node	*sorted;
	node	*oldnd;
	node	*newnd;

	sorted = ft_lst_init();
	while (ft_lst_size(lst) > 0)
	{
		oldnd = ft_lst_min(lst, cmp);
		newnd = ft_lst_new(oldnd->data);
		ft_lst_pushback(sorted, newnd);
		ft_lst_del(lst, oldnd);
	}
	ft_lst_del(lst, lst);
	return (sorted);
}
