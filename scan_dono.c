/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dono.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:19:11 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/25 11:33:02 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"
#define CHEESE t_counter *c = create_counter();

/*
** Trims the dono piece to place or to make space for the grid counter as a
** string thanks to strnew.
*/

char	*trim_dono(char const *straightdono, int grid_counter, int mult)
{
	char	*a;
	char	*b;

	a = ft_strnew(grid_counter);
	a[grid_counter--] = '\0';
	while (grid_counter >= 0)
		a[grid_counter--] = straightdono[mult--];
	b = ft_strtrima(a, '.');
	return (b);
}

/*
** gather_dono and trim_dono behave much like strsplit
*/

void	gather_dono(char **dono_col, char *buf, int count)
{
	int dono_count;
	int a;
	int c;

	dono_count = count;
	g_dono_count = dono_count - 1;
	a = 0;
	c = 1;
	while (a < (g_dono_count))
	{
		dono_col[a] = trim_dono(buf, 20, (20 * c) - 1);
		c++;
		a++;
	}
	dono_col[a] = NULL;
	print_raw_donos(dono_col);
}

/*
** Uses the structure called from the header to access the counters (x, y, z)
** "CHEESE" definition on top of the header
*/

int		count_and_copy(char *new_bu, char *phold, int a)
{
	CHEESE;
	while (phold[c->z])
	{
		if ((c->z == 20 || ((c->z - 20) % 21 == 0)) && phold[c->z] != '\n')
		{
			free(c);
			dono_error(1);
		}
		else if (phold[c->z] == '\n')
		{
			if ((c->z == 20 || ((c->z - 20) % 21 == 0)) && phold[c->z] == '\n')
			{
				a++;
				c->y--;
			}
			else
				new_bu[c->y] = 46;
		}
		else
			new_bu[c->y] = phold[c->z];
		c->y++;
		c->z++;
	}
	free(c);
	return (a);
}

/*
** Allocate necessary space for a new line
*/

void	unnewline_b(char *bu)
{
	char	*placeholder;
	int		a;
	char	*new_bu;

	a = 0;
	placeholder = bu;
	a = ft_strlen(placeholder);
	if (!(a == 20 || ((a - 20) % 21 == 0)))
		dono_error(1);
	new_bu = ft_strnew(a);
	if (new_bu == NULL)
		dono_error(1);
	a = count_and_copy(new_bu, placeholder, 1);
	if (!(g_dono_list = ft_memalloc((sizeof(char*) * (a + 1)))))
		dono_error(1);
	gather_dono(g_dono_list, new_bu, a + 1);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*b;

	b = malloc(546);
	ft_bzero(b, 546);
	if (argc != 2)
		dono_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dono_error(1);
	read(fd, b, 546);
	unnewline_b(b);
	close(fd);
	return (26);
}
