/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:16:16 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 16:56:44 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char **ft_split_line(char *line)
{
	int bufsize;
	int i;
	char **tokens;;

	bufsize = FT_TOK_BUFSIZE;
	i= 0;
	tokens = malloc(bufsize * sizeof(char*));
	if (!tokens) 
	{
		ft_putstr("minishell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	tokens = ft_strsplit(line, ' ');
	return tokens;
}
