/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:07:36 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/22 23:29:05 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef enum e_donotaipu
{
	oh = 0, 	 // 
	i_flat = 1,  //
	i_vert = 2,  //
	t_up = 3,	 //
	t_right = 4, //
	t_down = 5,  //
	t_left = 6,  //
	l_down = 7,  //
	l_right = 8, //
	l_left = 9,  //
	l_up = 10,	 //
	j_down = 11, //
	j_left = 12, //
	j_up = 13,	 //
	j_right = 14,//
	s_vert = 15, //
	s_flat = 16, //
	z_flat = 17, //
	z_vert = 18, //
	nada = 19
} t_donotaipu;

typedef struct 	s_dono
{
	t_donotaipu	taipu;
	uint8_t		placed;
}	t_dono;

typedef unsigned long long t_big;

void dono_error(int a);
void print_raw_donos(char **file_donos);
void create_grid(char **pass_donos, int a);
int populate_recurse(char **donos, char *dono_grid, int num);
void placeit(char* dono, char *dono_grid, int shift, int grid_size);
void placeit_tiny(char *dono, char *dono_grid, int shift);
int check_available(char *dono, char *grid, int a, int grid_size);
int check_avail_tiny(char *dono, char *grid, int a, int grid_size);

char **g_dono_list;
int g_dono_count;

#endif
