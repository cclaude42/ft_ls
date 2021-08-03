/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:56 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 18:38:30 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushfront (node *nil, node *new)
{
	if (!nil || !new)
		return ;
	new->prev = nil;
	new->next = nil->next;
	nil->next->prev = new;
	nil->next = new;
}
