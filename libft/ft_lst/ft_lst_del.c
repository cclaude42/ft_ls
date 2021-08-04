/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:10 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:58:26 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del (node *lst, node *nd)
{
	if (!lst || !nd)
		return ;
	nd->prev->next = nd->next;
	nd->next->prev = nd->prev;
	free(nd);
}
