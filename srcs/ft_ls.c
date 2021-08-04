/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:50:42 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:26:36 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int first = 1;

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
		return (-1000);
	else
		return (1000);
}

char get_type (mode_t m)
{
	if (S_ISREG(m))
		return ('-');
	else if (S_ISBLK(m))
		return ('b');
	else if (S_ISCHR(m))
		return ('c');
	else if (S_ISDIR(m))
		return ('d');
	else if (S_ISLNK(m))
		return ('l');
	else if (S_ISFIFO(m))
		return ('p');
	else if (S_ISSOCK(m))
		return ('s');
	return ('-');
}

void get_permissions (mode_t m, char *perm)
{
	ft_memset(perm, '-', 9);
	if (m & S_IRUSR)
		perm[0] = 'r';
	if (m & S_IWUSR)
		perm[1] = 'w';
	if (m & S_IXUSR)
		perm[2] = 'x';
	if (m & S_IRGRP)
		perm[3] = 'r';
	if (m & S_IWGRP)
		perm[4] = 'w';
	if (m & S_IXGRP)
		perm[5] = 'x';
	if (m & S_IROTH)
		perm[6] = 'r';
	if (m & S_IWOTH)
		perm[7] = 'w';
	if (m & S_IXOTH)
		perm[8] = 'x';
	perm[9] = 0;
}

void get_time (const time_t *timeptr, char *timestr)
{
	char	*timetmp;

	timetmp = ctime(timeptr);
	ft_memset(timestr, ' ', 12);
	ft_memcpy(timestr, timetmp + 4, 12);
	if (*timeptr + 15780000 < time(NULL))
		ft_memcpy(timestr + 7, timetmp + 19, 5);
	timestr[12] = 0;
}

void print_long (char *path, max ml)
{
	struct stat		st;
	char			type;
	char			perm[10];
	struct passwd	*pw;
	struct group	*gr;
	char			time[13];

	stat(path, &st);
	type = get_type(st.st_mode);
	get_permissions(st.st_mode, perm);
	pw = getpwuid(st.st_uid);
	gr = getgrgid(st.st_gid);
	get_time(&st.st_ctime, time);
	ft_printf("%c%s %*d %*s %*s %*d %s %s\n", type, perm, ml.lnmax, st.st_nlink,
		ml.pwmax, pw->pw_name, ml.grmax, gr->gr_name, ml.szmax, st.st_size,
		time, ft_strrchr(path, '/') + 1);
}

void prep_long (node *lst, max *max_length)
{
	struct stat		st;
	struct passwd	*pw;
	struct group	*gr;

	ft_memset(max_length, 0, sizeof(max));
	for (node *c = lst->next ; c != lst ; c = c->next)
	{
		stat(c->data, &st);
		pw = getpwuid(st.st_uid);
		gr = getgrgid(st.st_gid);
		max_length->sztot += (st.st_size - 1) / 1024 + 1;
		if ((unsigned int)ft_nbrlen(st.st_nlink) > max_length->lnmax)
			max_length->lnmax = ft_nbrlen(st.st_nlink);
		if (ft_strlen(pw->pw_name) > max_length->pwmax)
			max_length->pwmax = ft_strlen(pw->pw_name);
		if (ft_strlen(gr->gr_name) > max_length->grmax)
			max_length->grmax = ft_strlen(gr->gr_name);
		if ((unsigned int)ft_nbrlen(st.st_size) > max_length->szmax)
			max_length->szmax = ft_nbrlen(st.st_size);
	}
}

void print_dir (node *lst, char *path, unsigned int options)
{
	max		max_length;

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
		prep_long(lst, &max_length);
		printf("total %d\n", max_length.sztot);
		for (node *c = lst->next ; c != lst ; c = c->next)
			print_long(c->data, max_length);
	}
	else
	{
		for (node *c = lst->next ; c != lst ; c = c->next)
			ft_printf("%s\n", ft_strrchr(c->data, '/') + 1);
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
	if (options & LOWERT)
		lst = ft_lst_sort(lst, date_cmp);
	else
		lst = ft_lst_sort(lst, alpha_cmp);
	if (options & LOWERR)
		ft_lst_rev(lst);
	print_dir(lst, path, options);
	closedir(dir);
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
