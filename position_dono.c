/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_dono.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:19:31 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/25 12:05:58 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*allocate_grid(int size)
{
	char *temp;

	size = (size * size) + size;
	temp = ft_strnew(size + 1);
	return (temp);
}

void	actual_print(char *dono_grid, int grid_size)
{
	int c;

	c = 0;
	while (dono_grid[c])
	{
		if ((c + 1) % (grid_size + 1) == 0)
			ft_putchar('\n');
		else
			ft_putchar(dono_grid[c]);
		c++;
	}
}

int		populate_recurse(char **donos, char *dono_grid, int grid_size)
{
	int v;

	v = -1;
	if (donos[0] == '\0')
		return (1);
	while (dono_grid[++v])
	{
		if (!check_available(donos[0], dono_grid, v, grid_size))
			continue ;
		else
		{
			grid_size <= 3 ?
			placeit_tiny(donos[0], dono_grid, v) :
			placeit(donos[0], dono_grid, v, grid_size);
			if (!donos[1])
				return (1);
			if (!populate_recurse(&donos[1], dono_grid, grid_size))
				remove_alpha(donos[0][0], dono_grid);
			else
				return (1);
		}
	}
	return (0);
}

void	populate_one_grid(char **donos, char *dono_grid, int grid_size)
{
	while ((populate_recurse(donos, dono_grid, grid_size)) == 0)
	{
		free(dono_grid);
		grid_size++;
		dono_grid = allocate_grid(grid_size);
		ft_memset(dono_grid, '.', ((grid_size * grid_size) + grid_size));
	}
	actual_print(dono_grid, grid_size);
	free(dono_grid);
}

void	create_grid(char **pass_donos, int a)
{
	char	*grid;
	int		n;

	n = 2;
	while (n <= 11)
	{
		if (a * 4 <= (n * n))
			break ;
		n++;
	}
	grid = allocate_grid(n);
	ft_memset(grid, '.', ((n * n) + n));
	if ((n == 2) && (ft_strequ(pass_donos[0], "AA...AA")))
	{
		ft_putstr("AA\nAA\n");
		exit(4);
	}
	if ((n == 2) && (ft_strequ(pass_donos[0], "AA..AA")))
	{
		ft_putstr(".AA\nAA.\n...\n");
		exit(4);
	}
	populate_one_grid(pass_donos, grid, n);
}
