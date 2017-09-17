/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:33:17 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 22:16:18 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "built.h"

int ft_execute(char **args)
{
	int i;

	i = 0;
	if (args[0] == NULL)
		return 1;
	while (i < ft_num_builtins())
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
		i++;
	}
	return ft_launch(args);
}

int ft_pwd(char **args)
{
	char cwd[FT_BUFSIZE];

	(void)args;
	if (args[1] != '\0')
	{
		if (!(args[1][0] == '-' && (args[1][1] == 'L' || args[1][1] == 'P')))
		{
			ft_putstr("minishell: Too many arguments");
			ft_putchar('\n');
			return (1);
		}
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr(cwd);
		ft_putchar('\n');
	}
	else
		ft_putstr("minishell error");
	return (1);
}

int ft_cd(char **args)
{
	if (args[1] == NULL)
		ft_putstr("minishell: expected argument to \"cd\"\n");
	else 
	{
		if (chdir(args[1]) != 0)
			ft_putstr("minishell: No such dir\n");
	}
	return (1);
}

int ft_help(char **args)
{
	int i;

	(void)args;
	ft_putstr("Minishell\n");
	ft_putstr("List of commands:\n");
	i = 0;
	while (i < ft_num_builtins())
	{
		ft_putstr(builtin_str[i]);
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int ft_exit(char **args)
{
	(void)args;
	return (0);
}
