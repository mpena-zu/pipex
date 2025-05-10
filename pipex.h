/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:15:29 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/05/10 19:42:01 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

void	child_time(char **argv, char **envp, int *fd);
void	father_time(char **argv, char **envp, int *fd);
char	*path(char **envp, char *cmd1);
void	command_time(char **envp, char **cmd1);
void	print_error(char *message);
void	pipex_manager(int *fd, char **argv, char **envp);
void	free_time(char **str);

#endif