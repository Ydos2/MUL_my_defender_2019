/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script build buttons
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    general_data_t *general_data;
    int build_id;
    int cost;
    sfVector2f *pos;
    sfIntRect *collider;
} data_t;

void *scp_build_buttons_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[0];
    dg_entity_t *ent_gd = dg_get_entity(scene->entities, "general_data");
    dg_entity_t *entity = idata[1];
    sfVector2f pos = *((sfVector2f *)idata[4]);

    data->pos = dg_cpt_pos(pos.x, pos.y);
    data->general_data = dg_entity_get_component(ent_gd, "general_data");
    data->collider = cpt_box_collider(0, 0, 220 * 0.5, 220 * 0.5);
    dg_entity_add_component(entity, data->collider);
    dg_entity_add_component(entity, data->pos);
    data->build_id = idata[2];
    data->cost = idata[3];
    return data;
}

void scp_build_buttons_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    d->collider->left = d->pos->x;
    d->collider->top = d->pos->y;
    build_buttons_update_pos(data);
    if (sfIntRect_contains(d->collider, mouse.x, mouse.y)) {
        printf("lol\n");
    }
}

void scp_build_buttons_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}