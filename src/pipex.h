/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:57:56 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/02 12:32:11 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define STDIN		0
# define STDOUT		1
# define STDERR		2

typedef struct s_pipex
{
	char *firstComand;
	char *secondComand;
	size_t count_strings;
	size_t count_strings2;
	char **argVec; //= {argv[2],"-c","5","www.google.com", (char*)0};
	char **argVec2;
	char **argv;
	int fd_out;
	int fd_in;
	int fd[2];
}	t_pipex;


void	error_cmd(void);
void	error_premission(void);
void	error_file(void);
void	error_pipe(void);
void	error_pid(void);
char	**ft_split(char const *s, char c, size_t *count);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strcat(char *path, char *command);
char	*ft_strchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_paths(char *cmd, char **envm);
size_t ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
