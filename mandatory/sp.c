/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:34:50 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void sp_traite_RGB(char *str, char *er, t_scene *scene, int ind)
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
	scene->sp[ind].color.x = atod(col[0], 0, 255, scene);
	scene->sp[ind].color.y = atod(col[1], 0, 255, scene);
	scene->sp[ind].color.z = atod(col[2], 0, 255, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void sp_traite_point(char *str, char *er, t_scene *scene, int ind)
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
	scene->sp[ind].sphere_center.x = atod(col[0], MIN_INT, MAX_INT, scene);
	scene->sp[ind].sphere_center.y = atod(col[1], MIN_INT, MAX_INT, scene);
	scene->sp[ind].sphere_center.z = atod(col[2], MIN_INT, MAX_INT, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void sp(char **split, t_scene *scene)
{
	if(split[4])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2] && split[3])
	{
		(scene->nb_sp)--;
		sp_traite_point(split[1], "bad input for Sphere\n", scene, scene->nb_sp);
		scene->sp[scene->nb_sp].diameter = atod(split[2], MIN_INT, MAX_INT, scene);
		sp_traite_RGB(split[3], "bad input for Sphere\n", scene, scene->nb_sp);
	}
}