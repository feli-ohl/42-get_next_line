/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:09:32 by foehler           #+#    #+#             */
/*   Updated: 2026/02/06 12:28:31 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		mi_fd;
	char	*linea;

	mi_fd = open("ejemplo.txt", O_RDONLY);
	if (mi_fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	linea = get_next_line(mi_fd);
	printf("He leído: %s", linea);
	free(linea);
	close(mi_fd);
	return (0);
}
