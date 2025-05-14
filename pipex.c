/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:14:58 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/05/14 14:35:02 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *path(char **envp, char *cmd1)
{
	int		i;
    char    **paths;
    char    *real_path;

	i = 0;
    if (!envp)
        return (NULL);
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL); 
    paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
    real_path = find_real_path(paths, cmd1);
    free_time(paths);
    return (real_path);
}

void	command_time(char **envp, char **cmd1)
{
	char	*path_time;

	if (!cmd1 || !cmd1[0])
		print_error("Error: empty command");
	if (access(cmd1[0], X_OK) == 0)
		path_time = cmd1[0];
	else
		path_time = path(envp, cmd1[0]);
	if (path_time == NULL)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd1[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	if (execve(path_time, cmd1, envp) == -1)
		print_error("execve error");
}

void	child_time(char **argv, char **envp, int *fd)
{
	int		file1_fd;
	char	**cmd1;

	file1_fd = open(argv[1], O_RDONLY);
	if (file1_fd == -1)
		print_error("./pipex");
	dup2(file1_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file1_fd);
	close(fd[0]);
	close(fd[1]);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1 || !cmd1[0])
		print_error("Error command");
	command_time(envp, cmd1);
	free_time(cmd1);
}

void	second_child_time(char **argv, char **envp, int *fd)
{
	int		file2_fd;
	char	**cmd2;

	file2_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file2_fd == -1)
		print_error("./pipex");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2_fd, STDOUT_FILENO);
	close(file2_fd);
	close(fd[0]);
	close(fd[1]);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2 || !cmd2[0])
		print_error("Error command");
	command_time(envp, cmd2);
	free_time(cmd2);
}

void	pipex_manager(int *fd, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	
	pid = fork();
	if (pid == -1)
		print_error("Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		child_time(argv, envp, fd);
	}
	pid2 = fork();
	if (pid2 == -1)
			print_error("Fork error");
	if (pid2 == 0)
	{
		close(fd[1]);
		second_child_time(argv, envp, fd);
	}
	close(fd[0]);
	close(fd[1]);
    waitpid(pid, 0, 0);
    waitpid(pid2, 0, 0);
}
