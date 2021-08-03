/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 22:05:08 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int first = 1;

int alpha_cmp (void *d1, void *d2)
{
	char	*s1;
	char	*s2;

	s1 = ((struct dirent *)d1)->d_name;
	s2 = ((struct dirent *)d2)->d_name;

	return (ft_strcmp(s1, s2));
}

int date_cmp (void *d1, void *d2)
{
	struct stat		st;
	unsigned long	t1;
	unsigned long	t2;

	stat(((struct dirent *)d1)->d_name, &st);
	t1 = st.st_ctime;
	stat(((struct dirent *)d2)->d_name, &st);
	t2 = st.st_ctime;

	if (t1 > t2)
		return (-1000);
	else
		return (1000);
}

void print_long (struct dirent *ent)
{
	ft_printf("%s\n", ent->d_name);
}

void print_dir (node *lst, char *path, unsigned int options)
{
	if (options & UPPERR || options & MULTIARG)
	{
		if (first)
			ft_printf("%s:\n", path);
		else
			ft_printf("\n%s:\n", path);
		first = 0;
	}

	if (options & LOWERL)
	{
		// prep_long(lst);
		// printf("total %d\n");
		for (node *c = lst->next ; c != lst ; c = c->next)
			print_long(c->data);
	}
	else
	{
		for (node *c = lst->next ; c != lst ; c = c->next)
			ft_printf("%s\n", ((struct dirent *)(c->data))->d_name);
	}
}

void ft_ls (char *path, unsigned int options)
{
	node			*lst = ft_lst_init();
	DIR				*dir = opendir(path);
	struct dirent	*ent;

	while ((ent = readdir(dir)))
	{
		if (ent->d_name[0] != '.' || options & LOWERA)
			ft_lst_pushback(lst, ft_lst_new(ent));
	}
	if (options & LOWERT)
		lst = ft_lst_sort(lst, date_cmp);
	else
		lst = ft_lst_sort(lst, alpha_cmp);
	if (options & LOWERR)
		ft_lst_rev(lst);
	print_dir(lst, path, options);
	closedir(dir);
	(void)(options);
}

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
	if (count > 1)
		options = options | MULTIARG;
	for (unsigned int i = 0 ; i < count ; i++)
		ft_ls(av[i], options);
}
