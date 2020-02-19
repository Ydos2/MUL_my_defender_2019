/*
** EPITECH PROJECT, 2020
** cpt_button
** File description:
** cpt_button
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

dg_entity_t *ent_button(sfVector2f pos, char *text
    , void (*action)(dg_window_t *))
{
    dg_entity_t *button = dg_entity_create("button");

    dg_entity_add_component(button, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(button, cpt_scale(0.2, 0.2));
    dg_entity_add_component(button, cpt_box_collider(0, 0, 60, 225));
    dg_entity_add_component(button, component_action_create(action));
    dg_entity_add_component(button
        , component_text_create(200, text));
    dg_entity_add_component(button, dg_cpt_spritesheet(1));
    return button;
}