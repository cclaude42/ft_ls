/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:50:01 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 18:29:50 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node	*ft_lst_init (void)
{
	node	*nil;

	if (!(nil = malloc(sizeof(node))))
		return (NULL);
	nil->data = NULL;
	nil->prev = nil;
	nil->next = nil;
	return (nil);
}
