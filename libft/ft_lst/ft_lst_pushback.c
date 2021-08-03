/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:45 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 18:38:24 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback (node *nil, node *new)
{
	if (!nil || !new)
		return ;
	new->prev = nil->prev;
	new->next = nil;
	nil->prev->next = new;
	nil->prev = new;
}
