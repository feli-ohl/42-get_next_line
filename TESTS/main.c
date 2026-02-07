/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:09:32 by foehler           #+#    #+#             */
/*   Updated: 2026/02/07 09:32:46 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		mi_fd;
	char	*linea;
	int		i;

	mi_fd = open("TESTS/ejemplo1.txt", O_RDONLY);
	if (mi_fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	linea = get_next_line(mi_fd);
	i = 1;
	while (linea)
	{
		printf("Línea %d: %s", i, linea);
		i++;
		linea = get_next_line(mi_fd);
	}
	free(linea);
	close(mi_fd);
	return (0);
}
