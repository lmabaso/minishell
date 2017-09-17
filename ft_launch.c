/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:20:42 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 18:01:58 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int		ft_launch(char **args)
{
	pid_t pid;
	pid_t wpid;
	int status;
	char **envp;

	envp = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
			ft_putstr("command not found\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putstr("minishell error\n");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}
