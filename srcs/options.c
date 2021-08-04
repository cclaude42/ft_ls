/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:25 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 22:07:46 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void set_option (unsigned int *options, char c)
{
	if (c == 'R')
		*options = *options | UPPERR;
	else if (c == 'a')
		*options = *options | LOWERA;
	else if (c == 'l')
		*options = *options | LOWERL;
	else if (c == 'r')
		*options = *options | LOWERR;
	else if (c == 't')
		*options = *options | LOWERT;
}

void read_option (unsigned int *options, char *arg)
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
			if (ft_chrindex(arg[i], "Ralrt") != -1)
				set_option(options, arg[i]);
			else
				print_invalid(arg[i]);
		}
	}
}
