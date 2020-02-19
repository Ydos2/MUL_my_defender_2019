/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void *dg_init(dg_window_t *window, void *import)
{
    dg_scene_manager_create();
    dg_ressources_add_spritesheet("./img/background.jpg", 1920, 1080);
    dg_ressources_add_spritesheet("./img/button.png", 1104, 340);
    dg_ressources_add_spritesheet("./img/map-1.jpg", 1920, 1080);
    dg_scene_manager_add_scene(scene_game());
    dg_scene_manager_add_scene(scene_map_1());
    return 0;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    sfRenderWindow_clear(w->window, sfRed);
    dg_scene_manager_update(w, dt);
    return 0;
}

void dg_end(void *var, int id)
{
    dg_scene_manager_destroy();
    dg_ressources_destroy();
}

int main(int argc, char **argv)
{
    return dg_play((sfVector2u){1920, 1080}, "Defender", 0, NULL);
}