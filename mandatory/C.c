/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:27:14 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 21:26:37 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void C_traite_point(char *str, char *er, t_scene *scene)
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
	scene->C[scene->nb_C].viewpoint.x = atod(col[0], MIN_INT, MAX_INT, scene);
	scene->C[scene->nb_C].viewpoint.y = atod(col[1], MIN_INT, MAX_INT, scene);
	scene->C[scene->nb_C].viewpoint.z = atod(col[2], MIN_INT, MAX_INT, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void C_traite_vect(char *str, char *er, t_scene *scene)
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
	scene->C[scene->nb_C].orientation_vect.x = atod(col[0], -1, 1, scene);
	scene->C[scene->nb_C].orientation_vect.y = atod(col[1], -1, 1, scene);
	scene->C[scene->nb_C].orientation_vect.z = atod(col[2], -1, 1, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void C(char **split, t_scene *scene)
{
	if(split[4])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2] && split[3])
	{
		(scene->nb_C)--;
		C_traite_point(split[1], "bad input for Camera\n", scene);
		C_traite_vect(split[2], "bad input for Camera\n", scene);
		scene->C[scene->nb_C].Horizontal_field = atod(split[3], 0, 180, scene);
	}
	else
		err("bad input for Camera\n");
}