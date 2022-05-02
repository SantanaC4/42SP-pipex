/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:31:37 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/02 10:24:20 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char* argv[], char *envp[])
{
	char *firstComand;
	char *secondComand;
	size_t count_strings = 0;
	size_t count_strings2 = 0;
	char **argVec; //= {argv[2],"-c","5","www.google.com", (char*)0};
	char **argVec2;
	int fd_out;
	int fd_in;

	if (argc != 5)
	{
		write(1, "Usage : ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (0);
	}

	argVec = ft_split(argv[2],' ',&count_strings);
	argVec2 = ft_split(argv[3],' ',&count_strings2);

	if (!access(argv[1], F_OK) && access(argv[1], W_OK))
		error_premission();
	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_file();

	if (!access(argv[4], F_OK) && access(argv[4], R_OK))
		error_premission();
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		error_file();

	firstComand = ft_paths(argVec[0], envp);
	secondComand = ft_paths(argVec2[0], envp);
	printf("%s", envp[0]);

	int fd[2];
	if (pipe(fd) == -1)
		return 0;

	int pid1 = fork();
	if (pid1 < 0)
		return 0;

	if (pid1 == 0)
	{
		// Child process 1 (ping)
		dup2(fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd_in);
		close(fd[0]);
		close(fd[1]);

		if (execve(firstComand, argVec, envp) == -1)
			perror("Could not execute execve");
	}


	int pid2 = fork();
	if (pid2 < 0)
		return 3;

	if (pid2 == 0)
	{
		// Child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		close(fd[0]);
		close(fd[1]);

		if (execve(secondComand, argVec2, envp) == -1)
			perror("Could not execute execve");
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	size_t i = 0;
	while(i < count_strings)
	   free(argVec[i++]);
	i = 0;
	while(i < count_strings2)
	   free(argVec2[i++]);

	free(firstComand);
	free(secondComand);
	free(argVec);
	free(argVec2);
	return (0);
}
