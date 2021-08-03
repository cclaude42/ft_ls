/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:26:24 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 12:38:37 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_chars(const char *str, int *i, char *base)
{
	if (str == NULL || i == NULL)
		return ;
	while (ft_chrindex(str[*i], base) != -1)
		(*i)++;
}
