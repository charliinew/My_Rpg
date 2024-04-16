/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    free(entity);
}

entity_t *init_entity(sfTexture *asset)
{
    entity_t *entity = malloc(sizeof(entity_t));
    sfFloatRect ss_size;

    entity->pos = (sfVector2f){0, 0};
    entity->size = (sfVector2f){0, 0};
    entity->rect = (sfIntRect){0, 0, 0, 0};
    entity->frame_nbr = 0;
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, asset, sfTrue);
    ss_size = sfSprite_getGlobalBounds(entity->sprite);
    entity->sprite_sheet_size = (sfVector2f){ss_size.width, ss_size.height};
    return entity;
}
