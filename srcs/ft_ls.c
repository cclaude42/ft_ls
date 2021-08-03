/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 16:30:23 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void single_ls (char *path, unsigned int options)
{
	
}

// void multiple_ls (char **av, unsigned int ac, unsigned int options)
// {
//
// }

int main (int ac, char **av)
{
	unsigned int	options = 0;
	unsigned int	count = 0;

	for (int i = 1 ; i < ac ; i++)
	{
		if (av[i][0] == '-')
			read_option(&options, av[i]);
		else
			av[count++] = av[i];
	}
	if (count == 0)
		av[count++] = ".";
	// if (count > 1 || options & UPPERR)
	// 	multiple_ls(av, count, options);
	// else
		single_ls(av[0], options);
}
