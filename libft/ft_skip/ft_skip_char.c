/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:26:24 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 12:23:38 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_char(const char *str, int *i, char c)
{
	if (str == NULL || i == NULL)
		return ;
	while (str[*i] == c)
		(*i)++;
}