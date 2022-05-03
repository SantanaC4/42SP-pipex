/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:26:22 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/02 11:26:39 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "pipex.h"

void	error_cmd(void)
{
	write(2, "command not found\n", 18);
	exit(0);
}

void	error_file(void)
{
	write(2, "No such file or directory\n", 26);
	exit(0);
}

void	error_premission(void)
{
	write(2, "Permission denied\n", 18);
	exit(0);
}

void	error_pipe(void)
{
	write(2, "Pipe error\n", 11);
	exit(0);
}

void	error_pid(void)
{
	write(2, "Pid error\n", 10);
	exit(0);
}
