/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:00:16 by lmabaso           #+#    #+#             */
/*   Updated: 2017/09/16 19:57:04 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

int     ft_cd(char **args);
int     ft_help(char **args);
int     ft_exit(char **args);
int		ft_pwd(char **args);
char 	*builtin_str[] = {"cd", "help", "exit", "pwd"};
int 	(*builtin_func[]) (char **) = { &ft_cd, &ft_help, &ft_exit, &ft_pwd};
int 	ft_num_builtins(void) 
{ 
	return sizeof(builtin_str) / sizeof(char *);
}
#endif