/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:38:29 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void cy_traite_RGB(char *str, char *er, t_scene *scene, int ind)
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
	scene->cy[ind].color.x = atod(col[0], 0, 255, scene);
	scene->cy[ind].color.y = atod(col[1], 0, 255, scene);
	scene->cy[ind].color.z = atod(col[2], 0, 255, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void cy_traite_point(char *str, char *er, t_scene *scene, int ind)
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
	scene->cy[ind].cylinder_center.x = atod(col[0], MIN_INT, MAX_INT, scene);
	scene->cy[ind].cylinder_center.y = atod(col[1], MIN_INT, MAX_INT, scene);
	scene->cy[ind].cylinder_center.z = atod(col[2], MIN_INT, MAX_INT, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void cy_traite_vect(char *str, char *er, t_scene *scene, int ind)
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
	scene->cy[ind].axis_vect.x = atod(col[0], -1, 1, scene);
	scene->cy[ind].axis_vect.y = atod(col[1], -1, 1, scene);
	scene->cy[ind].axis_vect.z = atod(col[2], -1, 1, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void cy(char **split, t_scene *scene)
{
	if(split[6])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2] && split[3] && split[4] && split[5])
	{
		(scene->nb_cy)--;
		cy_traite_point(split[1], "bad input for Plane\n", scene, scene->nb_cy);
		cy_traite_vect(split[2], "bad input for Plane\n", scene, scene->nb_cy);
		scene->cy[scene->nb_sp].diameter = atod(split[3], MIN_INT, MAX_INT, scene);
		scene->cy[scene->nb_sp].height = atod(split[4], MIN_INT, MAX_INT, scene);
		cy_traite_RGB(split[5], "bad input for Plane\n", scene, scene->nb_cy);
	}
}