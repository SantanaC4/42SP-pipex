/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:31:37 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 02:39:55 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char* argv[])
{
	char *firstComand;
	char *secondComand;
	int count_strings = 0;
//	char **split;
	char **argVec; //= {argv[2],"-c","5","www.google.com", (char*)0};
	char **argVec2;
	int fd_out;
	int fd_in;


	argVec = ft_split(argv[2]," ",&count_strings);
	argVec2 = ft_split(argv[3]," ",&count_strings);

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4],O_WRONLY);

	firstComand = ft_strcat("/usr/bin/",argVec[0]);
	secondComand = ft_strcat("/usr/bin/",argVec2[0]);
	printf("%d",argc);


	int fd[2];
	if (pipe(fd) == -1)
		return 1;

	int pid1 = fork();
	if (pid1 < 0)
		return 2;

	if (pid1 == 0)
	{
		// Child process 1 (ping)
		dup2(fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd_in);
		close(fd[0]);
		close(fd[1]);

		if (execve(firstComand, argVec, NULL) == -1)
			perror("Could not execute execve");
	}


	int pid2 = fork();
	if (pid2 < 0)
	{
		return 3;
	}

	if (pid2 == 0)
	{
		// Child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		close(fd[0]);
		close(fd[1]);

		if (execve(secondComand, argVec2, NULL) == -1)
			perror("Could not execute execve");
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);



	free(firstComand);
	free(secondComand);
	free(argVec);
	free(argVec2);
	return 0;
}
