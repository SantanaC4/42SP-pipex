/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:57:56 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 23:49:35 by edrodrig         ###   ########.fr       */
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

enum	e_mode
{
	IN,
	OUTWRITE,
	OUTAPPEND
};

# define ERR_ARG	"Wrong usage. Invalid number of arguments.\n"
# define ERR_FILE	": invalid file.\n"
# define ERR_PIPE	"Error on initializing pipe.\n"
# define ERR_FORK	"Error on forking.\n"
# define ERR_CMD	": command not found.\n"


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
