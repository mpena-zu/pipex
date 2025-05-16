/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:58:24 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/05/16 15:51:45 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *message)
{
	perror(message);
	exit(1);
}

char	*find_real_path(char **paths, char *cmd1)
{
	int		i;
	char	*cut_paths;
	char	*real_path;

	i = 0;
	while (paths[i])
	{
		cut_paths = ft_strjoin(paths[i], "/");
		if (!cut_paths)
			return (NULL);
		real_path = ft_strjoin(cut_paths, cmd1);
		free(cut_paths);
		if (access(real_path, F_OK) == 0)
			return (real_path);
		free(real_path);
		i++;
	}
	return (NULL);
}

void	free_time(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
