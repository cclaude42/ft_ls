/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:50:09 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:59:17 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size (node *lst)
{
	node	*current;
	int		count;

	current = lst->next;
	count = 0;
	while (current != lst)
	{
		current = current->next;
		count++;
	}
	return (count);
}
