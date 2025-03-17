/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:23:39 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void A_traite_RGB(char *str, char *er, t_scene *scene)
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
	scene->A[scene->nb_A].color.x = atod(col[0], 0, 255, scene);
	scene->A[scene->nb_A].color.y = atod(col[1], 0, 255, scene);
	scene->A[scene->nb_A].color.z = atod(col[2], 0, 255, scene);
	// free(col[0]);
	// free(col[1]);
	// free(col[2]);
	// free(col);
	free_2(col);
}

void A(char **split, t_scene *scene)
{
	if(split[3])
	{
		scene->err = 1;
		return;
	}
	if(split[1] && split[2])
	{
		scene->A[--scene->nb_A].ratio = atod(split[1], 0, 1, scene);
		A_traite_RGB(split[2], "bad input for Ambient lighting\n", scene);
	}
	else
		err("bad input for Ambient lighting\n");
}