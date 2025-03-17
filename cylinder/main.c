#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../MLX42/include/MLX42/MLX42.h"  // Assure-toi que ce header est bien inclus pour ta version

#define WIDTH 800
#define HEIGHT 600

// Définition des structures pour Point, Vector, Projectile et Environment
typedef struct {
    double x, y, z;
} Point;

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Point position;
    Vector velocity;
} Projectile;

typedef struct {
    Vector gravity;
    Vector wind;
} Environment;

// Fonction pour additionner deux vecteurs
Vector add(Vector v1, Vector v2) {
    return (Vector) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

// Fonction pour multiplier un vecteur par un scalaire
Vector multiply(Vector v, double scalar) {
    return (Vector) {v.x * scalar, v.y * scalar, v.z * scalar};
}

// Fonction pour normaliser un vecteur
Vector normalize(Vector v) {
    double magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return multiply(v, 1.0 / magnitude);
}

// Fonction pour créer un projectile
Projectile create_projectile(Point position, Vector velocity) {
    return (Projectile) {position, velocity};
}

// Fonction pour créer un environnement
Environment create_environment(Vector gravity, Vector wind) {
    return (Environment) {gravity, wind};
}

// Fonction tick pour mettre à jour la position et la vitesse du projectile
Projectile tick(Environment env, Projectile proj) {
    // Calcul de la nouvelle position
    Point new_position = {
        proj.position.x + proj.velocity.x,
        proj.position.y + proj.velocity.y,
        proj.position.z + proj.velocity.z
    };

    // Calcul de la nouvelle vitesse
    Vector new_velocity = add(add(proj.velocity, env.gravity), env.wind);

    return create_projectile(new_position, new_velocity);
}

// Fonction pour dessiner le projectile avec miniLibX
void draw_projectile(mlx_t* mlx, mlx_image_t* img, Projectile proj) {
    (void)mlx;
    // Convertir les coordonnées pour les adapter à l'écran
    int x = (int)(proj.position.x * 100) + (WIDTH / 2);  // Multiplier pour voir la trajectoire
    int y = (int)(proj.position.y * 100) + (HEIGHT / 2); // Décalage pour centrer

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        mlx_put_pixel(img, x, y, 0xFF0000FF);  // Dessiner le pixel en rouge (0xFF0000FF)
    }
}

// Fonction pour mettre à jour la fenêtre à chaque tick
void update(void* param) {
    mlx_t* mlx = (mlx_t*)param;
    static Projectile p = { {0, 1, 0}, {1, 1, 0} };
    static Environment e = { {0, -0.1, 0}, {-0.01, 0, 0} };
    static mlx_image_t* img = NULL;

    // Si l'image n'est pas encore initialisée, on la crée
    if (!img)
        img = mlx_new_image(mlx, WIDTH, HEIGHT);

    // Nettoyer l'image à chaque tick
    mlx_image_to_window(mlx, img, 0, 0);  // Affiche l'image
    mlx_close_window(mlx);  // Nettoyer la fenêtre à chaque itération pour éviter des dessins superposés

    // Mettre à jour la position du projectile
    p = tick(e, p);

    // Dessiner le projectile à la nouvelle position
    draw_projectile(mlx, img, p);
    // Afficher l'image à la fenêtre
    mlx_image_to_window(mlx, img, 0, 0);

    // Condition d'arrêt (quand le projectile touche le sol)
    if (p.position.y <= 0) {
        printf("The projectile hit the ground.\n");
        mlx_terminate(mlx);  // Ferme la fenêtre après le tir
    }
}

int main() {
    // Initialisation de MLX
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Projectile Simulation", true);
    if (!mlx) {
        printf("MLX initialization failed.\n");
        return 1;
    }

    // Démarrer la boucle d'événements
    mlx_loop_hook(mlx, update, mlx);

    // Boucle principale de MLX
    mlx_loop(mlx);
    while(1){}
    mlx_terminate(mlx);
    return 0;
}
