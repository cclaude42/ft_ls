/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:12:29 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/03 21:50:58 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>

# define MULTIARG 32
# define UPPERR 16
# define LOWERA 8
# define LOWERL 4
# define LOWERR 2
# define LOWERT 1

void read_option (unsigned int *options, char *arg);

#endif
