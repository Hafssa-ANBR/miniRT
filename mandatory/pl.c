/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:36:19 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void pl_traite_RGB(char *str, char *er, t_scene *scene, int ind)
{
	char **col;

	col = NULL;
	col = ft_split(str, ',');
	if(!col[0] || !col[1] || !col[2] || col[3])
	{
		err(er);
		scene->err = 1;
		return;
	}
	scene->pl[ind].color.x = atod(col[0], 0, 255, scene);
	scene->pl[ind].color.y = atod(col[1], 0, 255, scene);
	scene->pl[ind].color.z = atod(col[2], 0, 255, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void pl_traite_point(char *str, char *er, t_scene *scene, int ind)
{
	char **col;

	col = NULL;
	col = ft_split(str, ',');
	if(!col[0] || !col[1] || !col[2] || col[3])
	{
		err(er);
		scene->err = 1;
		return;
	}
	scene->pl[ind].point.x = atod(col[0], MIN_INT, MAX_INT, scene);
	scene->pl[ind].point.y = atod(col[1], MIN_INT, MAX_INT, scene);
	scene->pl[ind].point.z = atod(col[2], MIN_INT, MAX_INT, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void pl_traite_vect(char *str, char *er, t_scene *scene, int ind)
{
	char **col;

	col = NULL;
	col = ft_split(str, ',');
	if(!col[0] || !col[1] || !col[2] || col[3])
	{
		err(er);
		scene->err = 1;
		return;
	}
	scene->pl[ind].normal_vect.x = atod(col[0], -1, 1, scene);
	scene->pl[ind].normal_vect.y = atod(col[1], -1, 1, scene);
	scene->pl[ind].normal_vect.z = atod(col[2], -1, 1, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void pl(char **split, t_scene *scene)
{
	if(split[4])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2] && split[3])
	{
		(scene->nb_pl)--;
		pl_traite_point(split[1], "bad input for Plane\n", scene, scene->nb_pl);
		pl_traite_vect(split[2], "bad input for Plane\n", scene, scene->nb_pl);
		pl_traite_RGB(split[3], "bad input for Plane\n", scene, scene->nb_pl);
	}
}