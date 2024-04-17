/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

sfSprite *wich_back(rpg_t *rpg)
{
    if (rpg->biome[rpg->scene]->back)
        return (rpg->biome[rpg->scene]->back->sprite.sprite);
    return NULL;
}

void manage_movements(rpg_t *rpg)
{
    if (rpg->key_state[sfKeyD])
        manage_right(rpg);
    if (rpg->key_state[sfKeyQ])
        manage_left(rpg);
    if (rpg->key_state[sfKeyZ])
        manage_up(rpg);
    if (rpg->key_state[sfKeyS])
        manage_down(rpg);
    if (!rpg->key_state[sfKeyS] && !rpg->key_state[sfKeyD] &&
        !rpg->key_state[sfKeyZ] && !rpg->key_state[sfKeyQ])
        rpg->heros->npc->act_action = STAND;
    sfSprite_setPosition(rpg->heros->npc->entity->sprite,
    rpg->heros->npc->entity->pos);
}
