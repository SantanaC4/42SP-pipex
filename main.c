/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:15:55 by edrodrig          #+#    #+#             */
/*   Updated: 2022/04/30 06:17:40 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char	**ft_split(char const *s, char c);
int ft_strlen(char *str);
char *ft_strcat(char *path, char *command);

int main(int argc, char* argv[])
{
	char *firstComand;
	char *secondComand;
	char **split;
	char *argVec[] = {argv[2],"-c","5","www.google.com", (char*)0};
	char *argVec2[] = {argv[3],"rtt", (char*)0};
	int fd_out;
	int fd_in;


	split = ft_split(argv[2], ' ');

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4],O_WRONLY);
	firstComand = ft_strcat("/usr/bin/",argv[2]);
	secondComand = ft_strcat("/usr/bin/",argv[3]);

	printf("%d", argc);
	printf("\n%s", split[0]);

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
	free(split);
	return 0;
}
