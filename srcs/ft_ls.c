/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 22:42:03 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void recurse_ls (node *lst, unsigned int options, int *ret)
{
	struct stat		st;

	for (node *c = lst->next ; c != lst ; c = c->next)
	{
		lstat(c->data, &st);
		if (S_ISDIR(st.st_mode)
			&& ft_strcmp(ft_strrchr(c->data, '/') + 1, ".")
			&& ft_strcmp(ft_strrchr(c->data, '/') + 1, ".."))
		{
			parse_dir(c->data, options, ret);
		}
	}
}

void parse_dir (char *path, unsigned int options, int *ret)
{
	node			*lst;
	DIR				*dir;
	struct dirent	*ent;
	char			*fullpath;

	dir = opendir(path);
	if (!dir)
	{
		ft_printf("ls: cannot open directory \'%s\': Permission denied\n", path);
		*ret = 2;
		return ;
	}
	lst = ft_lst_init();
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
	lst = sort_dir(lst, options);
	print_dir(lst, path, options);
	if (options & UPPERR)
		recurse_ls(lst, options, ret);
	ft_lst_free(lst);
}

void ft_ls (node *dirs, node *files, unsigned int options, int *ret)
{
	if (ft_lst_empty(dirs) && ft_lst_empty(files) && *ret == 0)
		ft_lst_pushback(dirs, ft_lst_new(ft_strdup(".")));
	if (ft_lst_size(dirs) + ft_lst_size(files) > 1)
		options = options | MULTIARG;

	files = sort_dir(files, options);
	if (!ft_lst_empty(files))
		print_file(files, options);
	ft_lst_free(files);

	dirs = sort_dir(dirs, options);
	for (node *c = dirs->next ; c != dirs ; c = c->next)
		parse_dir(c->data, options, ret);
	ft_lst_free(dirs);
}

int main (int ac, char **av)
{
	node			*dirs = ft_lst_init();
	node			*files = ft_lst_init();
	unsigned int	options = 0;
	int				ret = 0;
	struct stat		st;

	for (int i = 1 ; i < ac ; i++)
	{
		if (av[i][0] == '-')
			read_option(&options, av[i]);
		else if (lstat(av[i], &st))
		{
			ft_printf("ft_ls: cannot access \'%s\': No such file or directory\n", av[i]);
			ret = 2;
		}
		else if (S_ISDIR(st.st_mode))
			ft_lst_pushback(dirs, ft_lst_new(ft_strdup(av[i])));
		else
			ft_lst_pushback(files, ft_lst_new(ft_strdup(av[i])));
	}

	ft_ls(dirs, files, options, &ret);

	return (ret);
}
