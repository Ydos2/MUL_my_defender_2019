/*
** EPITECH PROJECT, 2020
** enemy_data
** File description:
** enemy_data
*/

#ifndef ENEMY_DATA_H_
#define ENEMY_DATA_H_

typedef struct enemy_data
{
    int *id;
    sfVector2f *pos;
    dg_entity_t *entity;
    float *health;
} enemy_data_t;

#endif /*ENEMY_DATA_H_*/