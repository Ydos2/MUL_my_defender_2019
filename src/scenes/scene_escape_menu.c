/*
** EPITECH PROJECT, 2020
** scene_escape_menu
** File description:
** scene_escape_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void go_to_resume(dg_window_t *w)
{
    dg_scene_t *old_scene = dg_scene_manager_get_scene("escape_menu");
    dg_scene_t *new_scene = dg_scene_manager_get_scene("game");
    dg_entity_t *music_ent = dg_get_entity(new_scene->entities, "music");
    sfMusic *music_music = dg_entity_get_component(music_ent, "sound");
    sfMusic_play(music_music);

    old_scene->run = 0;
    old_scene->display = 0;
    new_scene->run = 1;
    new_scene->display = 1;
}

static void go_to_menu(dg_window_t *w)
{
    dg_scene_t *old_scene = dg_scene_manager_get_scene("escape_menu");
    dg_scene_t *new_scene = dg_scene_manager_get_scene("main_menu");
    dg_scene_t *scene = dg_scene_manager_get_scene("game");
    dg_entity_t *music_ent = dg_get_entity(scene->entities, "music");
    sfMusic *music_music = dg_entity_get_component(music_ent, "sound");
    sfMusic_stop(music_music);
    dg_entity_t *music_ent_game = dg_get_entity(new_scene->entities, "music");
    sfMusic *music__game = dg_entity_get_component(music_ent_game, "sound");
    sfMusic_play(music__game);

    old_scene->run = 0;
    old_scene->display = 0;
    new_scene->run = 1;
    new_scene->display = 1;
    scene->run = 0;
    scene->display = 0;
}

static void go_to_quit(dg_window_t *w)
{
    w->quit = 1;
}

static void go_to_reload(dg_window_t *w)
{
    dg_scene_manager_reload("game", scene_game());
    go_to_resume(w);
}

dg_scene_t *scene_escape_menu(void)
{
    dg_scene_t *scene = dg_scene_create("escape_menu");

    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 400}, 1, "Resume", &go_to_resume));
    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 500}, 1, "Reload", &go_to_reload));
    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 600}, 1, "Quit to menu", &go_to_menu));
    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 700}, 1, "Quit Game", &go_to_quit));
    dg_scene_add_ent(scene, ent_sprite(3, 2.75, 150, -50));
    dg_scene_add_ent(scene, ent_text(700, 175, 200, "MY DEFENDER"));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    scene->run = 0;
    scene->display = 0;
    return scene;
}