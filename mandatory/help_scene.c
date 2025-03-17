/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:18:12 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double atod(char *str, double min, double max, t_scene *scene)
{
	int		i;
	int		sg;
	double	lnb;
	double	rnb;

	sg = 1;
	lnb = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		lnb = lnb * 10 + (str[i] - '0');
		i++;
	}
	if(str[i] == '.')
	{
		i++;
		rnb = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			lnb += rnb * (str[i] - '0') ;
			rnb *= 0.1;
			i++;
		}
	}
	if(lnb * sg < min || lnb * sg > max)
		scene->err = 1;//erreuuuuuuur apres
	return (lnb * sg);
}

void free_2(char **col)
{
	int i;

	i = 0;
	while(col[i])
	{
		free(col[i]);
		i++;
	}
	free(col);
}
// void traite_RGB(char *str, char *er, t_scene *scene, int ind)
// {
// 	char **col;

// 	col = NULL;
// 	col = ft_split(str, ',');
// 	if(!col[0] || !col[1] || !col[2])
// 	{
// 		err(er);
// 		return;
// 	}
// 	scene->A[ind].color.x = atod(col[0], 0, 255, scene);
// 	scene->A[ind].color.y = atod(col[1], 0, 255, scene);
// 	scene->A[ind].color.z = atod(col[2], 0, 255, scene);
// 	free(col[0]);
// 	free(col[1]);
// 	free(col[2]);
// 	free(col);
// }

// void traite_point(char *str, char *er, t_scene *scene, int ind)
// {
// 	char **col;

// 	col = NULL;
// 	col = ft_split(str, ',');
// 	if(!col[0] || !col[1] || !col[2])
// 	{
// 		err(er);
// 		return;
// 	}
// 	scene->C[ind].viewpoint.x = atod(col[0], MIN_INT, MAX_INT, scene);
// 	scene->C[ind].viewpoint.y = atod(col[1], MIN_INT, MAX_INT, scene);
// 	scene->C[ind].viewpoint.z = atod(col[2], MIN_INT, MAX_INT, scene);
// 	free(col[0]);
// 	free(col[1]);
// 	free(col[2]);
// 	free(col);
// }

// void traite_vect(char *str, char *er, t_scene *scene, int ind)
// {
// 	char **col;

// 	col = NULL;
// 	col = ft_split(str, ',');
// 	if(!col[0] || !col[1] || !col[2])
// 	{
// 		err(er);
// 		return;
// 	}
// 	scene->C[ind].orientation_vect.x = atod(col[0], -1, 1, scene);
// 	scene->C[ind].orientation_vect.y = atod(col[1], -1, 1, scene);
// 	scene->C[ind].orientation_vect.z = atod(col[2], -1, 1, scene);
// 	free(col[0]);
// 	free(col[1]);
// 	free(col[2]);
// 	free(col);
// }
