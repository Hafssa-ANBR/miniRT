/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_funct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:02:07 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 20:38:37 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void sp(char **split, t_scene *scene)
// {
// 	(scene->nb_sp)--;
// 	traite_point(split[1], "bad input for Sphere\n", scene, scene->nb_sp);
// 	scene->sp[scene->nb_sp].diameter = atod(split[2], MIN_INT, MAX_INT, scene);
// 	traite_RGB(split[3], "bad input for Sphere\n", scene, scene->nb_sp);
// }
// void pl(char **split, t_scene *scene)
// {
// 	(scene->nb_pl)--;
// 	traite_point(split[1], "bad input for Plane\n", scene, scene->nb_pl);
// 	traite_vect(split[2], "bad input for Plane\n", scene, scene->nb_pl);
// 	traite_RGB(split[3], "bad input for Plane\n", scene, scene->nb_pl);
// }

// void cy(char **split, t_scene *scene)
// {
// 	(scene->nb_cy)--;
// 	traite_point(split[1], "bad input for Plane\n", scene, scene->nb_cy);
// 	traite_vect(split[2], "bad input for Plane\n", scene, scene->nb_cy);
// 	scene->cy[scene->nb_sp].diameter = atod(split[3], MIN_INT, MAX_INT, scene);
// 	scene->cy[scene->nb_sp].height = atod(split[4], MIN_INT, MAX_INT, scene);
// 	traite_RGB(split[5], "bad input for Plane\n", scene, scene->nb_cy);
// }