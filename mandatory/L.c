/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:30:40 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 21:27:13 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void L_traite_point(char *str, char *er, t_scene *scene)
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
	scene->L[scene->nb_L].lightpoint.x = atod(col[0], MIN_INT, MAX_INT, scene);
	scene->L[scene->nb_L].lightpoint.y = atod(col[1], MIN_INT, MAX_INT, scene);
	scene->L[scene->nb_L].lightpoint.z = atod(col[2], MIN_INT, MAX_INT, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void L(char **split, t_scene *scene)
{
	if(split[4])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2])
	{
		(scene->nb_L)--;
		L_traite_point(split[1], "bad input for Light\n", scene);
		scene->L[scene->nb_L].ratio = atod(split[2], 0, 1, scene);
	}
}