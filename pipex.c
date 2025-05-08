/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:14:58 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/05/08 18:28:01 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **envp, char *cmd1)
{
	int		i;
	char	**paths;
	char	*cut_paths;
	char	*real_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		cut_paths = ft_strjoin(paths[i], "/");
		real_path = ft_strjoin(cut_paths, cmd1);
		if (access(real_path, F_OK) == 0)
			return (real_path);
		i++;
	}
	return (0);
}

void	command_time(char **envp, char **cmd1)
{
	char	*path_time;

	if (!cmd1 || !cmd1[0])
		print_error("Error: empty command");
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
		print_error("Error opening input file");
	dup2(file1_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file1_fd);
	close(fd[0]);
	close(fd[1]);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1 || !cmd1[0])
		print_error("Error command");
	command_time(envp, cmd1);
}

void	father_time(char **argv, char **envp, int *fd)
{
	int		file2_fd;
	char	**cmd2;

	file2_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file2_fd == -1)
		print_error("Error opening output file");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2_fd, STDOUT_FILENO);
	close(file2_fd);
	close(fd[0]);
	close(fd[1]);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2 || !cmd2[0])
		print_error("Error command");
	command_time(envp, cmd2);
}

void	print_error(char *message)
{
	perror(message);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Bad Arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		print_error("Pipe error");
	pid = fork();
	if (pid == -1)
		print_error("Fork error");
    if (pid == 0)
    {
        close(fd[0]);
        child_time(argv, envp, fd);
        exit(1);
    }
    else
    {
        close(fd[1]);
        waitpid(pid, NULL, 0);
        father_time(argv, envp, fd);
    }
	return (0);
}
