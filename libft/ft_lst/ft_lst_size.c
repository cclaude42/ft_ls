/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:50:09 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 18:24:59 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size (node *nil)
{
	node	*current;
	int		count;

	current = nil->next;
	count = 0;
	while (current != nil)
	{
		current = current->next;
		count++;
	}
	return (count);
}
