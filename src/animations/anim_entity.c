/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void reverse_sprite(entity_t *entity, sfVector2i offset, float time)
{
    static float accu = 0;
    float frec = 1.0 / 10.0;

    sfSprite_setScale(entity->sprite, (sfVector2f){-1, 1});
    entity->rect_sprite.top = ABS(offset.y) * entity->size.y;
    accu += time;
    if (accu >= frec) {
        entity->rect_sprite.left -= entity->size.x;
        if (entity->rect_sprite.left <= 0)
            entity->rect_sprite.left = entity->size.x * (offset.x - 1);
        accu = 0;
        sfSprite_setTextureRect(entity->sprite, entity->rect_sprite);
    }
}

void right_sprite(entity_t *entity, sfVector2i offset, float time)
{
    static float accu = 1.0;
    float frec = 1.0 / 10.0;

    sfSprite_setScale(entity->sprite, (sfVector2f){1, 1});
    entity->rect_sprite.top = ABS(offset.y) * entity->size.y;
    accu += time;
    if (accu >= frec) {
        entity->rect_sprite.left += entity->size.x;
        if (entity->rect_sprite.left >= entity->size.y * offset.x)
            entity->rect_sprite.left = 0;
        accu = 0;
        sfSprite_setTextureRect(entity->sprite, entity->rect_sprite);
    }
}

void anim_entity(entity_t *entity, sfVector2i offset, float time)
{
    if (offset.y >= 0)
        right_sprite(entity, offset, time);
    else
        reverse_sprite(entity, offset, time);
}
