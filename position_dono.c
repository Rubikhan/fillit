/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_dono.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:19:31 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/23 00:36:29 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


char *allocate_grid(int sizzle)
{
	char *a;
	sizzle = sizzle * sizzle + sizzle;  
  	a = ft_strnew(sizzle + 1);
  	return (a);  
}  

  void actual_print(char *dono_grid, int grid_size)  
  {  
  	int c;  
  	c = 0;  
//	printf("\n");
  	while(dono_grid[c])  
  	{  
  		if ((c + 1) % (grid_size + 1) == 0)  
  			printf("\n");  
  		else  
  			printf("%c", dono_grid[c]);  
  		c++;  
  	}  
//	printf("\n");
  }  

void remove_alpha(char c, char *dono_grid)
{
	while(*dono_grid)
	{
		if (*dono_grid == c)
			*dono_grid = '.';
		dono_grid++;
	}
}

int  populate_recurse(char **donos, char *dono_grid, int grid_size)
{



	int v;
	v = -1;

	if (donos[0] == '\0')
		return(1);

	while(dono_grid[++v])
	{
		if(!check_available(donos[0], dono_grid, v, grid_size))
			;
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
					return(1);
						
		   }
	}
	
	return(0);
}

void populate_one_grid(char **donos, char *dono_grid, int grid_size)  
{

/* 	printf("%s", dono_grid); */
/* 	for (int i = 0; i < g_dono_count; i++) */
/* 		printf("%s", donos[i]); */
/* 	printf("%d", grid_size); */





	while ((populate_recurse(donos, dono_grid, grid_size)) == 0)
	{
		free(dono_grid);
		grid_size++;
		dono_grid = allocate_grid(grid_size);
		memset(dono_grid, '.', ((grid_size * grid_size) + grid_size));  
	}

	actual_print(dono_grid, grid_size);
	free(dono_grid);
  
}


void create_grid(char **pass_donos, int a) 
{	
  	int z;  
	char *grid;
	int n;
	n = 2;
	while (n <= 11)
	{
		if (a * 4 <= (n * n))
			break;
		else
			n++;
	}
  	z = 0;  
	grid = allocate_grid(n);
  	memset(grid, '.', ((n * n) + n));  
	if((n == 2) && (ft_strequ(pass_donos[0], "AA...AA"))) // fine edge case imo
	{
		ft_putstr("AA\nAA\n");
		exit(4);
		return ;
	}
/* 	else if((n == 2) && (ft_strequ(pass_donos[0], "##..##"))) // might want to revisit this? */
/* 	{ */
/* 		grid = allocate_grid(3); */
/* 		populate_one_grid(pass_donos, grid, n); */
/* 		return ; */
/* 	} */
	populate_one_grid(pass_donos, grid, n );
}
