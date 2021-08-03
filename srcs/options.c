/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:25 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 16:23:18 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_help (void)
{
	ft_printf("Usage: ls [OPTION]... [FILE]...\n");
	ft_printf("Lists information about the FILEs (the current directory by default).\n");
	ft_printf("Sorts entries alphabetically if -t is not specified.\n\n");
	ft_printf("Options :\n");
	ft_printf("  -a            do not ignore entries starting with .\n");
	ft_printf("  -l            use a long listing format\n");
	ft_printf("  -r            reverse order while sorting\n");
	ft_printf("  -R            list subdirectories recursively\n");
	ft_printf("  -t            sort by modification time, newest first\n\n");
	ft_printf("  --help        display this help and exit\n\n");
	ft_printf("Exit status:\n");
	ft_printf(" 0  if OK,\n");
	ft_printf(" 1  if minor problems (e.g., cannot access subdirectory),\n");
	ft_printf(" 2  if serious trouble (e.g., cannot access command-line argument).\n");
	exit(0);
}

void print_unrecognized (char *s)
{
	ft_printf("ls: unrecognized option \'%s\'\n", s);
	ft_printf("Try \'ls --help\' for more information.\n");
	exit(2);
}

void print_invalid (char c)
{
	ft_printf("ls: invalid option -- \'%c\'\n", c);
	ft_printf("Try \'ls --help\' for more information.\n");
	exit(2);
}

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
