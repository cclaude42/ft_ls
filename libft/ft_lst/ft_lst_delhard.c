/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delhard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:10 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 19:11:25 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del (node *nil, node *nd)
{
	if (!nil || !nd)
		return ;
	nd->prev->next = nd->next;
	nd->next->prev = nd->prev;
	free(nd->data);
	free(nd);
}
