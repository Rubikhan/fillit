/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:26:38 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/24 15:44:03 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_avail_tiny(char *dono, char *grid, int a, int grid_size)
{
	int z;
	int y;
	int x;

	y = ft_strlen(grid);
	z = 0;
	x = 0;
	while (dono[z] && a < y)
	{
		if (dono[z] == '.' && dono[z - 1] >= 'A')
			z++;
		if ((a + 1) % (grid_size + 1) == 0 && dono[z] >= 'A')
			return (0);
		else if ((dono[z] >= 'A' && grid[a] == '.'))
			x++;
		if (x == 4)
			return (1);
		z++;
		a++;
	}
	return (0);
}

t_counter	*create_counter(void)
{
	t_counter	*retstruct;

	retstruct = ft_memalloc(sizeof(t_counter));
	retstruct->w = 0;
	retstruct->x = 0;
	retstruct->y = 0;
	retstruct->z = 0;
	return (retstruct);
}

#define FREERET(retnum) if(free_counter(c))  return(retnum);

int			check_available(char *dono, char *grid, int a, int grid_size)
{
	t_counter	*c;

	c = create_counter();
	c->y = ft_strlen(grid);
	if (grid_size <= 3)
		return (check_avail_tiny(dono, grid, a, grid_size));
	while (dono[c->z] && a < c->y)
	{
		if (dono[c->z] == '.' && dono[c->z - 1] >= 'A')
		{
			c->w = grid_size - 4;
			while (c->w--)
				a++;
		}
		if ((a + 1) % (grid_size + 1) == 0 && dono[c->z] >= 'A')
			FREERET(0);
		if (dono[c->z] >= 'A' && grid[a] == '.')
			c->x++;
		if (c->x == 4)
			FREERET(1);
		c->z++;
		a++;
	}
	free(c);
	return (0);
}

void		placeit_tiny(char *dono, char *dono_grid, int shift)
{
	int		b;
	int		j;
	char	*y;
	char	*x;

	b = 0;
	j = 0;
	y = dono;
	x = dono_grid;
	while (shift--)
		b++;
	while (y[j])
	{
		if (y[j] == '.' && y[j - 1] >= 'A')
			j++;
		if (y[j] >= 'A')
			x[b] = y[j];
		b++;
		j++;
	}
}

void		placeit(char *dono, char *dono_grid, int shift, int grid_size)
{
	int		z;
	int		b;
	int		j;
	char	*y;
	char	*x;

	b = 0;
	j = 0;
	y = dono;
	x = dono_grid;
	while (shift--)
		b++;
	while (y[j])
	{
		if (y[j] == '.' && y[j - 1] >= 'A')
		{
			z = grid_size - 4;
			while (z--)
				b++;
		}
		if (y[j] >= 'A')
			x[b] = y[j];
		b++;
		j++;
	}
}
