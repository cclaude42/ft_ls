/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 18:06:29 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int alpha_cmp (void *p1, void *p2)
{
	return (ft_strcmp(ft_strrchr(p1, '/'), ft_strrchr(p2, '/')));
}

int date_cmp (void *p1, void *p2)
{
	struct stat		st;
	unsigned long	t1;
	unsigned long	t2;

	stat(p1, &st);
	t1 = st.st_ctime;
	stat(p2, &st);
	t2 = st.st_ctime;

	if (t1 > t2)
		return (-1);
	else
		return (1);
}

void recurse_ls (node *lst, unsigned int options)
{
	struct stat		st;

	for (node *c = lst->next ; c != lst ; c = c->next)
	{
		stat(c->data, &st);
		if (S_ISDIR(st.st_mode)
			&& ft_strcmp(ft_strrchr(c->data, '/') + 1, ".")
			&& ft_strcmp(ft_strrchr(c->data, '/') + 1, ".."))
		{
			ft_ls(c->data, options);
		}
	}
}

void ft_ls (char *path, unsigned int options)
{
	node			*lst = ft_lst_init();
	DIR				*dir = opendir(path);
	struct dirent	*ent;
	char			*fullpath;

	while ((ent = readdir(dir)))
	{
		if (ent->d_name[0] != '.' || options & LOWERA)
		{
			fullpath = ft_strjoinf(path, DONTFREE, "/", DONTFREE);
			fullpath = ft_strjoinf(fullpath, FREE, ent->d_name, DONTFREE);
			ft_lst_pushback(lst, ft_lst_new(fullpath));
		}
	}
	closedir(dir);
	if (options & LOWERT)
		lst = ft_lst_sort(lst, date_cmp);
	else
		lst = ft_lst_sort(lst, alpha_cmp);
	if (options & LOWERR)
		ft_lst_rev(lst);
	print_dir(lst, path, options);
	if (options & UPPERR)
		recurse_ls(lst, options);
	ft_lst_free(lst);
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
