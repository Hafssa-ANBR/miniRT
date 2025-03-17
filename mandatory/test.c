/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:06:52 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 10:13:13 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int main()
{
    char **split;
    char var[300] = "   hafssa      is     h    bbbb    ";
    int i = 0;

    split =NULL;
    split = ft_split(var, ' ');
    while(split[i])
    {
        printf("%s\n",split[i]);
        i++;
    }
}