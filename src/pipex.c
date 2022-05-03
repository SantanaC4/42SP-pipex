/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:31:37 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/02 13:55:59 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exit_pipex(t_pipex *pipex, char *message, int code, int free_msg);

static void get_cmd(t_pipex *pipex, char **argv, char **envp)
{
	pipex->count_strings = 0;
	pipex->count_strings2 = 0;
	pipex->argVec = ft_split(argv[2],' ',&pipex->count_strings);
	pipex->argVec2 = ft_split(argv[3],' ',&pipex->count_strings2);

	if (!access(argv[1], F_OK) && access(argv[1], W_OK))
		error_premission();
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot open file: ",""), 1, 1);

	if (!access(argv[4], F_OK) && access(argv[4], R_OK))
		error_premission();
	pipex->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_out == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot open file: ",""), 1, 1);

	pipex->firstComand = ft_paths(pipex->argVec[0], envp);
	pipex->secondComand = ft_paths(pipex->argVec2[0], envp);
}

static void child_process(t_pipex *pipex, char **envm)
{
	close(pipex->fd[0]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd_in);
	close(pipex->fd[1]);

	if (execve(pipex->firstComand, pipex->argVec, envm) == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot execute: ", pipex->firstComand), 1, 1);

	exit(0);
}

static void child_process2(t_pipex *pipex, char **envm)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_out);
	close(pipex->fd[0]);
	close(pipex->fd[1]);

	if (execve(pipex->secondComand, pipex->argVec2, envm) == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot execute: ", pipex->secondComand), 1, 1);

	exit(0);
}

static void free_pipex(t_pipex *pipex)
{
	size_t i;

	i = 0;
	while(i < pipex->count_strings)
	   free(pipex->argVec[i++]);
	i = 0;
	while(i < pipex->count_strings2)
	   free(pipex->argVec2[i++]);

	free(pipex->firstComand);
	free(pipex->secondComand);
	free(pipex->argVec);
	free(pipex->argVec2);
}

static void	ft_check_argv(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_pipex(NULL, "cannot open in file!", 1, 0);
	close(fd);
	if (access(argv[1], F_OK) == -1)
	{
		fd = open(argv[1], O_CREAT, 0666);
		if (fd == -1)
			ft_exit_pipex(NULL, "cannot create out file!", 1, 0);
		close(fd);
	}
}

int main(int argc, char* argv[], char *envp[])
{
	t_pipex pipex;

	if (argc != 5)
		ft_exit_pipex(NULL, "invalid number os arguments!", 1, 0);

	ft_check_argv(argv);
	get_cmd(&pipex, argv, envp);
	if (pipe(pipex.fd) == -1)
		return 0;
	int pid1 = fork();
	if (pid1 < 0)
		return 0;
	if (pid1 == 0)
		child_process(&pipex, envp);
	waitpid(pid1, NULL, 0);
	int pid2 = fork();
	if (pid2 < 0)
		return 3;
	if (pid2 == 0)
		child_process2(&pipex, envp);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(pid2, NULL, 0);
	free_pipex(&pipex);

	return (0);
}

void ft_exit_pipex(t_pipex *pipex, char *message, int code, int free_msg)
{
	free_pipex(pipex);
	write(1, message, ft_strlen(message));
	if (free_msg)
		free(message);
	exit(code);
}
