/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:25:35 by kamofoke          #+#    #+#             */
/*   Updated: 2020/02/21 10:38:16 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "./libft/libft.h"

char	**g_envp;

int		exec_bin(char **arg);
int		len_of_envp(char **envp);
int		ft_echo(char **arg);
int		ft_setenv(char **arg);
int		ft_unsetenv(char **arg);
char	*find_envp(char *str);
int		find_position(char *str);
int		ft_cd(char **arg);
void	set_envp(char *arg, char *value);

#endif
