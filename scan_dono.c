/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dono.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:19:11 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/23 00:52:38 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "./libft/libft.h"

void dono_error(int a)
{
	if (a == 1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	else if (a == 0)
	{
		ft_putstr("usage: tetromino_file\n");
		exit(0);
	}
	else
	{
		ft_putstr("dono_error called O_O\n");
	}
}

char *trim_dono( char const *straightdono,  int nijuuni, int mult) // rename nijuuni
{
 	char *a; 
	char *b;


 	a = ft_strnew(nijuuni); 
// 	if (a == NULL) 
// 		return (NULL); 
 	a[nijuuni--] = '\0'; 
 	while (nijuuni >= 0) 
	{
			a[nijuuni--] = straightdono[mult--]; 
	}
	b = ft_strtrima(a, '.');
	return(b);
}

/*
**check_dono and organ_dono behave much like strsplit
**check_dono's while loop is strange with dono_count - 1
*/

void gather_dono(char **dono_col, char *buf, int count) //hmmm g_dono_list instead of dono_col?
 { 
	 int dono_count;
	 int a;
	 int b;
	 int c;
	 dono_count = count;
	 g_dono_count = dono_count - 1; 
//	 printf("dono_count: %d\n", dono_count);
	 a = 0;
	 b = 0;
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
** not sure we have access to NULL for fillit
** added placeholder during debugging but might not be necessary
*/

void unnewline_b(char *bu)
{
	char *placeholder;
	int a; // a should be dono_count
	char *new_bu;
	int z;
	int y;
//	char **donos;
	y = 0;
	z = 0;
	a = 0;
	placeholder = bu;
	a = ft_strlen(placeholder);
//	printf("ft_strlen: %d\n", a);
	if (!(a == 20 || ((a - 20) % 21 == 0))) //this can be a macro to save space?
		dono_error(1);
	new_bu = ft_strnew(a);
	if (new_bu == NULL) 
		dono_error(1);
	a = 1;
	while (placeholder[z]) //########FUNCTION########
	{
		if ((z == 20  || ((z - 20) % 21 == 0)) && placeholder[z] != '\n')
				dono_error(1);
		else if (placeholder[z] == '\n')
		{
			if((z == 20  || ((z - 20) % 21 == 0)) && placeholder[z] == '\n')
			{
				a++;
				y--;
			}

			else
				new_bu[y] = 46;
		}
		else
		{
			new_bu[y] = placeholder[z];
		}
		y++;
		z++;
	} //#############END FUNCTION##################
	if (!(g_dono_list = ft_memalloc((sizeof(char*) * (a + 1) )))) 
//		if (!(g_dono_list = ft_memalloc((sizeof(char*) * a + 1 ))))  THIS IS WRONG
		dono_error(1);
	gather_dono(g_dono_list, new_bu, a + 1); // a should be dono_count
}

int	main(int argc, char *argv[])
{
	int fd;
	char *b;

	b = malloc(546); //547 (25 X 21) + 20 
	ft_bzero(b, 546);
	if (argc != 2) 
		dono_error(0); //dono_error(0) //usage
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
		dono_error(1); //dono_error(1); //regular error
	read(fd, b, 546);
	//ft_putstr(b);
	unnewline_b(b);
	close(fd);
	return (26);
}
