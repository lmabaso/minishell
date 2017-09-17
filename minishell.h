/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:42:55 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 22:05:45 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "gnl/libft/libft.h"
# include "gnl/get_next_line.h"

#define FT_TOK_BUFSIZE 64
#define FT_BUFSIZE 1024

int     ft_launch(char **args);
int 	ft_execute(char **args);
void    cmd_loop(void);
char 	**ft_split_line(char *line);
char    *ft_read_line(void);
int		get_next_line(const int fd, char **line);
#endif
