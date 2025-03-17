/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:29:25 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/14 17:08:12 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	err(char *str)
{
	while(*str)
		write(1, str++, 1);
}

void	my_close(char *str, int fd, char *msg)
{
	free(str);
	close(fd);
	err(msg);
}

char *read_file(char *file)
{
	char *line;
	int fd;
	char *cont;

	cont = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	
	line = get_next_line(fd);
	
	if (!line || !line[0])
		my_close(line, fd, "empty file\n");
	while(line)
	{
		cont = ft_strjoin(cont, line, 1);
		free(line);
		line = get_next_line(fd);
	}
	return(cont);
}

void check_elemt(char *elmt,t_scene *scene)
{
	char **split;
	char *tab[7] = {"A", "C", "L", "sp", "pl", "cy"};
	t_shapes funct[7] = {A, C, L, sp, pl, cy};
	int i;

	i = 0;
	split = NULL;
	split = multi_split(elmt, " \t");
	while(tab[i])
	{
		if (!ft_strcmp(split[0], tab[i]))
			funct[i](split, scene);
		i++;
	}
	
	// i = 0;
	// while(split[i])
	// {
	// 	free(split[i]);
	// 	i++;
	// }
	// free(split);
	free_2(split);
}

char *mini_split(char *str, char c, char t)
{
	char *word;
	int i;

	i = 0;

	if (str == NULL)
		return (NULL);
	word = NULL;
	while (str[i] == c || str[i] == t)
		i++;
	if (str[i])
		word = new_word(str, &i, c);
	return (word);
}
void which_one(char *split, t_scene *scene)
{
	char *first;
	int i;
	char *tab[7] = {"A", "C", "L", "sp", "pl", "cy"};
	int *var[7] = {&scene->nb_A, &scene->nb_C, &scene->nb_L, &scene->nb_sp, &scene->nb_pl, &scene->nb_cy};

	i = 0;
	first = mini_split(split, ' ','\t');
	while(tab[i])
	{
		if (!ft_strcmp(first, tab[i]))
		{
			(*var[i])++;
			break;
		}
		i++;
	}
	free(first);
}

void alloc_scene(t_scene *scene)
{
	scene->A = NULL;
    scene->C = NULL;
    scene->L = NULL;
    scene->sp = NULL;
    scene->pl = NULL;
    scene->cy = NULL;
	if(scene->nb_A)
		scene->A = (t_A *)malloc(scene->nb_A * sizeof(t_A));
	if(scene->nb_C)
		scene->C = (t_C *)malloc(scene->nb_C * sizeof(t_C));
	if(scene->nb_L)
		scene->L = (t_L *)malloc(scene->nb_L * sizeof(t_L));
	if(scene->nb_sp)
		scene->sp = (t_sp *)malloc(scene->nb_sp * sizeof(t_sp));
	if(scene->nb_pl)
		scene->pl = (t_pl *)malloc(scene->nb_pl * sizeof(t_pl));
	if(scene->nb_cy)
		scene->cy = (t_cy *)malloc(scene->nb_cy * sizeof(t_cy));
}
void init_scene(char *cont, t_scene *scene)
{
	char **split;
	int i;

	i = 0;
	split = NULL;
	scene->nb_A = 0;
	scene->nb_C = 0;
	scene->nb_L = 0;
	scene->nb_sp = 0;
	scene->nb_pl = 0;
	scene->nb_cy = 0;
	scene->err = 0;
	split = ft_split(cont, '\n');
	free(cont);
	while(split[i])
	{
		which_one(split[i],scene);
		i++;
	}
	alloc_scene(scene);//ou bien pass the adresse
	i = 0;
	while(split[i])
	{
		check_elemt(split[i],scene);
		// if(i == 1){
		// 	printf("%s\n",split[1]);
		// 	exit(1);
		// }
		i++;
	}
	// i = 0;
	// while(split[i])
	// {
	// 	free(split[i]);
	// 	i++;
	// }
	// free(split);
	free_2(split);
}
void lil()
{
	system("leaks miniRT");
}
int main(int argc, char ** argv)
{
	atexit(lil);
	char *cont;
	t_scene scene;

	// scene = NULL;//ok or i need to alloc
	if(argc != 2 || ft_strlen(argv[1]) < 3 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 3],".rt", 3))//<3 ou bien <=3
	{
		
		err("bad arguments, we need 1 parameter and file with an extension .fdf\n");
		return (1);// modif affich
	}
	cont = read_file(argv[1]);
	if(!cont)
		err("file can't open\n");
	else if (!cont[0])
		err("empty file\n");
	else
	{
		init_scene(cont, &scene);
	}
	if (scene.err == 1)
	{
		err("bad input\n");
		free(scene.A);
		free(scene.C);
		free(scene.L);
		free(scene.sp);
		free(scene.pl);
		free(scene.cy);
		return(1);
	}
	// exit(1);
	printf("%f\n",scene.A[0].ratio);
	printf("%f\n",scene.A[0].color.x);
	printf("%f\n",scene.A[0].color.y);
	printf("%f\n",scene.A[0].color.z);
	printf("\n#########################################\n\n");
	printf("%f\n",scene.C[0].Horizontal_field);
	printf("%f\n",scene.C[0].viewpoint.x);
	printf("%f\n",scene.C[0].viewpoint.y);
	printf("%f\n",scene.C[0].viewpoint.z);
	printf("%f\n",scene.C[0].orientation_vect.x);
	printf("%f\n",scene.C[0].orientation_vect.y);
	printf("%f\n",scene.C[0].orientation_vect.z);
	printf("\n#########################################\n\n");
	
	printf("%f\n",scene.L[0].lightpoint.x);
	printf("%f\n",scene.L[0].lightpoint.y);
	printf("%f\n",scene.L[0].lightpoint.z);
	printf("%f\n",scene.L[0].ratio);
	printf("\n#########################################\n\n");
	printf("%f\n",scene.sp[0].sphere_center.x);
	printf("%f\n",scene.sp[0].sphere_center.y);
	printf("%f\n",scene.sp[0].sphere_center.z);
	printf("%f\n",scene.sp[0].color.x);
	printf("%f\n",scene.sp[0].color.y);
	printf("%f\n",scene.sp[0].color.z);
	printf("%f\n",scene.sp[0].diameter);
	printf("\n#########################################\n\n");
	printf("%f\n",scene.pl[0].point.x);
	printf("%f\n",scene.pl[0].point.y);
	printf("%f\n",scene.pl[0].point.z);
	printf("%f\n",scene.pl[0].normal_vect.x);
	printf("%f\n",scene.pl[0].normal_vect.y);
	printf("%f\n",scene.pl[0].normal_vect.z);
	printf("%f\n",scene.pl[0].color.x);
	printf("%f\n",scene.pl[0].color.y);
	printf("%f\n",scene.pl[0].color.z);
	printf("\n#########################################\n\n");
	printf("%f\n",scene.cy[0].cylinder_center.x);
	printf("%f\n",scene.cy[0].cylinder_center.y);
	printf("%f\n",scene.cy[0].cylinder_center.z);
	printf("%f\n",scene.cy[0].axis_vect.x);
	printf("%f\n",scene.cy[0].axis_vect.y);
	printf("%f\n",scene.cy[0].axis_vect.z);
	printf("%f\n",scene.cy[0].color.x);
	printf("%f\n",scene.cy[0].color.y);
	printf("%f\n",scene.cy[0].color.z);
	printf("%f\n",scene.cy[0].diameter);
	printf("%f\n",scene.cy[0].height);
	printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
	printf("%f\n",scene.pl[1].point.x);
	printf("%f\n",scene.pl[1].point.y);
	printf("%f\n",scene.pl[1].point.z);
	printf("%f\n",scene.pl[1].normal_vect.x);
	printf("%f\n",scene.pl[1].normal_vect.y);
	printf("%f\n",scene.pl[1].normal_vect.z);
	printf("%f\n",scene.pl[1].color.x);
	printf("%f\n",scene.pl[1].color.y);
	printf("%f\n",scene.pl[1].color.z);
	free(scene.A);
	free(scene.C);
	free(scene.L);
	free(scene.sp);
	free(scene.pl);
	free(scene.cy);
	return(0);
}
