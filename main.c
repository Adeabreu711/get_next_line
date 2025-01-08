/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:23:04 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/08 14:25:17 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//MANDATORY

//#include "get_next_line.h"
// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	char	*temp;

// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		printf("[%s]\n", temp);
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	printf("[%s]\n", temp);
// 	close(fd);
// 	return (0);
// }

//BONUS

//#include "get_next_line_bonus.h"
// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	int		fd2;
// 	char	*temp;

// 	if (argc != 3)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[2], O_RDONLY);
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		printf("file 1 : [%s]\n", temp);
// 		free (temp);
// 		temp = get_next_line(fd2);
// 		printf("file 2 : [%s]\n", temp);
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	printf("[%s]\n", temp);
// 	close(fd);
// 	return (0);
// }

