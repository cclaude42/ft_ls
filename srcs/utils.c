/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:02:36 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 22:02:58 by cclaude          ###   ########.fr       */
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

	lstat(p1, &st);
	t1 = st.st_ctime;
	lstat(p2, &st);
	t2 = st.st_ctime;

	if (t1 > t2)
		return (-1);
	else
		return (1);
}

node *sort_dir (node *lst, unsigned int options)
{
	if (options & LOWERT)
		lst = ft_lst_sort(lst, date_cmp);
	else
		lst = ft_lst_sort(lst, alpha_cmp);
	if (options & LOWERR)
		ft_lst_rev(lst);
	return (lst);
}
