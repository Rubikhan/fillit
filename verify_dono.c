/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_dono.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:52:58 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/22 21:52:48 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_dono	og_donos[20] = { 
 	{oh, 0}, 
 	{i_flat, 0}, 
 	{i_vert, 0}, 
 	{t_up, 0}, 
 	{t_right, 0}, 
 	{t_down, 0}, 
 	{t_left, 0}, 
 	{l_down, 0}, 
 	{l_right, 0}, 
 	{l_left, 0}, 
 	{l_up, 0}, 
 	{j_down, 0}, 
 	{j_left, 0}, 
 	{j_up, 0}, 
 	{j_right, 0}, 
 	{s_vert, 0}, 
 	{s_flat, 0}, 
 	{z_vert, 0}, 
 	{z_flat, 0}, 
 	{nada, 0}, 
 }; 

void alphabetize(char *dono, char alpha, int len)
{
	
	int i;
	i = 0;

		while (i < len)
		{
			if (*dono == '#')
			{
				*dono = alpha + 65;

			}
			dono++;
			i++;
		}
	return;
}

#define IDDONO(str, strlit, taipu) if(ft_strequ(str, strlit)) return(taipu);

t_donotaipu	dono_id(char *str)  
{  
	IDDONO(str, "##...##", oh); // 0
	IDDONO(str,"####", i_flat);
	IDDONO(str,"#....#....#....#", i_vert);
	IDDONO(str,"#...###", t_up);
	IDDONO(str,"#....##...#", t_right); 
	IDDONO(str,"###...#", t_down); //5
	IDDONO(str,"#...##....#", t_left);
	IDDONO(str,"##....#....#", l_down);
	IDDONO(str,"###..#", l_right);
	IDDONO(str,"#..###", l_left);
	IDDONO(str,"#....#....##", l_up); //10
	IDDONO(str,"##...#....#", j_down);
	IDDONO(str,"###....#", j_left);
	IDDONO(str,"#....#...##", j_up);
	IDDONO(str,"#....###", j_right);
	IDDONO(str,"#....##....#", s_vert); //15
	IDDONO(str,"##..##", s_flat);
	IDDONO(str,"##....##", z_flat);
	IDDONO(str,"#...##...#", z_vert);
	dono_error(1);
	return(nada);
}  

void print_raw_donos(/* char **file_donos */)
{
	int a;
	a = 0;
	int len;
	
	while(a < g_dono_count)
	{
		if(dono_id(g_dono_list[a]) != nada)
		{
			len = ft_strlen(g_dono_list[a]);
			alphabetize(g_dono_list[a], a, len);
		}
		a++;
	}

	create_grid(g_dono_list,  a);
}


