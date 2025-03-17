/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:17:54 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/17 14:21:56 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>// deleted

typedef struct tuple
{
    double x;
    double y;
    double z;
    int w;//point = 1 & vector = 0
}t_tuple;
bool is_point(t_tuple *t);
bool is_vector(t_tuple *t);// * not neccecary
bool equl(double a, double b);// abs(a-b) < 0.00001 = EPSILON a defnir
bool equl_tuple(t_tuple *a, t_tuple *b);// i can retuen an int value , pos, neg,nul

//familiar arithmetic operators

t_tuple *add(t_tuple *a, t_tuple *b);
// Point (w = 1) + Vecteur (w = 0) = Point (w = 1) ✅
// Vecteur (w = 0) + Vecteur (w = 0) = Vecteur (w = 0) ✅
t_tuple *sub(t_tuple *a, t_tuple *b);
// Point (w = 1) - point (w = 1) = Vecteur (w = 0) ✅
// Vecteur (w = 0) - Vecteur (w = 0) = Vecteur (w = 0) ✅
// Point (w = 1) - Vecteur (w = 0) = Point (w = 1) ✅ déplacer le point en arrière selon le vecteur donné
t_tuple *ops(t_tuple *a);//inverse , (-x, -y, -z, w)
// Tuple inverse = subtract(tuple(0, 0, 0, 0), vecteur);
t_tuple *mul(t_tuple *a, double b);
t_tuple *div(t_tuple *a, double b);

// other operations
float magnitude(t_tuple *a);
// float magnitude(Tuple t) {
//     return sqrt(t.x * t.x + t.y * t.y + t.z * t.z);
// }
t_tuple *normalize(t_tuple *a);
// return tuple(v.x / magnitude(v),
// v.y / magnitude(v),
// v.z / magnitude(v),
// v.w / magnitude(v))
double dot(t_tuple *a, t_tuple *b);//produit scalaire
// return a.x * b.x +
// a.y * b.y +
// a.z * b.z +
// a.w * b.w
t_tuple *cross(t_tuple *a, t_tuple *b);//produit vectoriel
// return vector(
//         a.y * b.z - a.z * b.y,
//         a.z * b.x - a.x * b.z,
//         a.x * b.y - a.y * b.x
//     )

//color
// addition et soustraction de couleurs,
// multiplication d'une couleur par un scalaire,
// multiplication d'une couleur par une autre couleur.
t_tuple *color(double r, double g, double b);
t_tuple *add_color(t_tuple *a, t_tuple *b);
t_tuple *sub_color(t_tuple *a, t_tuple *b);
t_tuple *mul_color(t_tuple *a, double b);
t_tuple *mul_color_color(t_tuple *a, t_tuple *b);
//return color(a.x * b.x, a.y * b.y, a.z * b.z);

//matrices
// dans matrices pour verifier si 2 matrices sont egales 
//on compare chaque element de la matrice avec la methode des flottants pour que la cmparaison soit correcte
bool equl_matrix(double **a, double **b);
//pour additionner 2 matrices on additionne chaque element de la matrice
double **add_matrix(double **a, double **b);
//pour soustraire 2 matrices on soustrait chaque element de la matrice
double **sub_matrix(double **a, double **b);
//pour multiplier une matrice par un scalaire on multiplie chaque element de la matrice par le scalaire
double **mul_matrix(double **a, double b);
//pour multiplier 2 matrices on multiplie chaque element de la matrice par chaque element de l'autre matrice
double **mul_matrix_matrix(double **a, double **b);
//pour multiplier une matrice par un vecteur on multiplie chaque element de la matrice par chaque element du vecteur
t_tuple *mul_matrix_tuple(double **a, t_tuple *b);
//transposer une matrice c'est echanger les lignes et les colonnes
double **transpose(double **a);
//pour calculer le determinant d'une matrice 2x2 on fait a*d - b*c
// la transposition des matrices c’est essentiel pour ombrer correctement tes objets
double **inverse(double **a); // a * b = c  =>  a = c * inverse(b)
// inverse pour  transformer et déformer les formes dans un ray tracer

// verif si inversible ou nn

//inverse d'une matrice 2x2 on fait 1/determinant * (d -b -c a)
// Ce terme vient de son utilisation dans la résolution des systèmes d’équations. En effet, le déterminant permet de savoir si un système a une solution :

// Si le déterminant est nul, alors le système n’a pas de solution.
// Sinon, il en a au moins une.

double determinant(double **a);// ad − bc
// //////////Ici, le déterminant servira uniquement à calculer l’inverse d’une matrice.

double **identity_matrix(void);
//pour creer une matrice identite on met 1 sur la diagonale et 0 partout ailleurs
double submatrix(double **a, int row, int col);
// 👉 Le minor d’un élément (i, j) dans une matrice est le déterminant de la sous-matrice obtenue en supprimant la ligne i et la colonne j.
double minor(double **a, int row, int col);// C’est le déterminant d’une sous-matrice
// 👉 Le cofacteur d’un élément (i, j) dans une matrice est le minor de cet élément multiplié par (-1)^(i+j).
double cofactor(double **a, int row, int col);

double determinant_3x3(double **a);

double **adjugate(double **a);

//inverse d'une matrice plus grande que 2x2

    // Pour les matrices plus grandes,
    //  l'inverse peut être calculé via la matrice des cofacteurs 
    //  et la transposée de la matrice des cofacteurs (également appelée matrice adjointe). L’inverse d’une matrice est donné par :
    //inverseMatrix ← (1 / det) * adj
    //

//transformations
//translation
double **translation(double x, double y, double z);
//scaling
double **scaling(double x, double y, double z);
//Reflection
double **reflection(double x, double y, double z);
//La réflexion est une mise à l’échelle avec une valeur négative
//rotation
double **rotation_x(double rad);
double **rotation_y(double rad);
double **rotation_z(double rad);
//shearing
//x est modifié en fonction de y et z.
// y est modifié en fonction de x et z.
// z est modifié en fonction de x et y
double **shearing(double xy, double xz, double yx, double yz, double zx, double zy);

#endif