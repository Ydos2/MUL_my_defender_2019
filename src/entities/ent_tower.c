/*
** EPITECH PROJECT, 2020
** ent_tower
** File description:
** ent_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

const void (*towerCreation[1])(dg_entity_t *) = {&tower_basic};

dg_entity_t *ent_tower(sfVector2f pos, int id)
{
    dg_entity_t *entity = dg_entity_create("tower");

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_spritesheet(7));
    towerCreation[id](entity);
    return entity;
}