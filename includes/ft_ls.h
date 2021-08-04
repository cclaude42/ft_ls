/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:12:29 by cclaude           #+#    #+#             */
/*   Updated: 2021/08/04 22:41:24 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define MULTIARG 32
# define UPPERR 16
# define LOWERA 8
# define LOWERL 4
# define LOWERR 2
# define LOWERT 1

# define M_DIR 1
# define M_FILE 0

typedef struct		s_max
{
	unsigned int	bltot;
	unsigned int	lnmax;
	unsigned int	pwmax;
	unsigned int	grmax;
	unsigned int	szmax;
}					max;


// Main func
void parse_dir (char *path, unsigned int options, int *ret);

// Options
void read_option (unsigned int *options, char *arg);

// Print
void print_dir (node *lst, char *path, unsigned int options);
void print_file (node *files, unsigned int options);
void print_help (void);
void print_unrecognized (char *s);
void print_invalid (char c);

// Long format
void print_long (char *path, max ml, int mode);
void prep_long (node *lst, max *max_length);

// Utils
node *sort_dir (node *lst, unsigned int options);
int alpha_cmp (void *p1, void *p2);
int date_cmp (void *p1, void *p2);

#endif
