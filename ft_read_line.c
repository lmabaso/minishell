/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 14:56:46 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 21:00:56 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "gnl/get_next_line.h"
#include <stdio.h>

char	*ft_read_line(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}
