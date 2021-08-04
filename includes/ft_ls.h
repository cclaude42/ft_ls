/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:12:29 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 17:15:01 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define MULTIARG 32
# define UPPERR 16
# define LOWERA 8
# define LOWERL 4
# define LOWERR 2
# define LOWERT 1

typedef struct		s_max
{
	unsigned int	sztot;
	unsigned int	lnmax;
	unsigned int	pwmax;
	unsigned int	grmax;
	unsigned int	szmax;
}					max;

void read_option (unsigned int *options, char *arg);

#endif
