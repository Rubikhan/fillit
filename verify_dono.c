/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_dono.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:52:58 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/24 17:34:35 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define IDDONO(str, strlit, taipu) if(ft_strequ(str, strlit)) return(taipu);

int			free_counter(t_counter *freeme)
{
	free(freeme);
	return (1);
}

t_donotaipu	dono_id(char *str)
{
	IDDONO(str, "##...##", oh);
	IDDONO(str, "####", i_flat);
	IDDONO(str, "#....#....#....#", i_vert);
	IDDONO(str, "#...###", t_up);
	IDDONO(str, "#....##...#", t_right);
	IDDONO(str, "###...#", t_down);
	IDDONO(str, "#...##....#", t_left);
	IDDONO(str, "##....#....#", l_down);
	IDDONO(str, "###..#", l_right);
	IDDONO(str, "#..###", l_left);
	IDDONO(str, "#....#....##", l_up);
	IDDONO(str, "##...#....#", j_down);
	IDDONO(str, "###....#", j_left);
	IDDONO(str, "#....#...##", j_up);
	IDDONO(str, "#....###", j_right);
	IDDONO(str, "#....##....#", s_vert);
	IDDONO(str, "##..##", s_flat);
	IDDONO(str, "##....##", z_flat);
	IDDONO(str, "#...##...#", z_vert);
	dono_error(1);
	return (nada);
}

void		alphabetize(char *dono, char alpha, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (*dono == '#')
			*dono = alpha + 'A';
		dono++;
		i++;
	}
	return ;
}

void		remove_alpha(char c, char *dono_grid)
{
	while (*dono_grid)
	{
		if (*dono_grid == c)
			*dono_grid = '.';
		dono_grid++;
	}
}

void		print_raw_donos(void)
{
	int a;
	int len;

	a = 0;
	while (a < g_dono_count)
	{
		if (dono_id(g_dono_list[a]) != nada)
		{
			len = ft_strlen(g_dono_list[a]);
			alphabetize(g_dono_list[a], a, len);
		}
		a++;
	}
	create_grid(g_dono_list, a);
}
