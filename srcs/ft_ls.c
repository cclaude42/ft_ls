/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/02 19:34:45 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



void read_opt (options *opt, char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
	{
		if (ft_strcmp(arg, "--help") == 0)
			print_help();
		else
			print_unrecognized(arg);
	}
	else if (arg[0] == '-')
	{
		for (int i = 1 ; arg[i] ; i++)
		{
			if (ft_isin(arg[i], "Ralrt"))
				set_opt(opt, arg[i]);
			else
				print_invalid(arg[i]);
		}
	}
}

int main (int ac, char **av)
{
	options	opt;

	ft_bzero(&opt, sizeof(opt));
	for (int i = 0 ; i < ac ; i++)
	{
		if (av[i][0] == '-')
			read_opt(&opt, av[i]);
	}
	for (int i = 0 ; i < ac ; i++)
	{

	}
}
