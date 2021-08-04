/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:04 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:58:22 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear (node *lst)
{
	node	*current;
	node	*next;

	if (!lst)
		return ;
	current = lst->next;
	while (current != lst)
	{
		next = current->next;
		if (current->data)
			free(current->data);
		free(current);
		current = next;
	}
}
