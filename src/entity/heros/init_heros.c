/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void destroy_inventory(back_obj_t **list)
{
    back_obj_t *next = NULL;
    back_obj_t *curr = *list;

    while (curr) {
        next = curr->next;
        destroy_back_obj(curr);
        curr = next;
    }
    *list = NULL;
}

void destroy_heros(heros_t *heros)
{
    if (heros->inventory)
        destroy_inventory(&(heros->inventory));
    destroy_npc(heros->npc);
    free(heros);
}

void set_action_tab_heros(heros_t *heros)
{
    heros->npc->action[ATTACK_F] = (sfVector2i){6, 6};
    heros->npc->action[ATTACK_B] = (sfVector2i){6, 5};
    heros->npc->action[ATTACK_L] = (sfVector2i){6, -3};
    heros->npc->action[ATTACK_R] = (sfVector2i){6, 3};
    heros->npc->action[MOVE_R] = (sfVector2i){6, 1};
    heros->npc->action[MOVE_L] = (sfVector2i){6, -1};
    heros->npc->action[MOVE_F] = (sfVector2i){-1, 0};
    heros->npc->action[MOVE_B] = (sfVector2i){-1, 0};
    heros->npc->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_heros(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){15, 15, 30, 70};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){20, 50, 25, 65};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){5, 30, 40, 55};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){35, 30, 40, 55};
}

effect_t **create_effect_tab_heros(
    sfTexture **text_tab, sfSprite *heros_sprite)
{
    effect_t **effect_tab = malloc(sizeof(effect_t *) * 4);

    effect_tab[LEVEL_UP_HEROS] = create_effect(
        text_tab[LEVEL_UP_TEXT], true, (sfVector2i){7, 1}, heros_sprite);
    effect_tab[BLOOD_HEROS] = create_effect(
        text_tab[BLOOD_TEXT], true, (sfVector2i){8, 1}, heros_sprite);
    effect_tab[PICK_HEROS] = create_effect(
        text_tab[COIN_TEXT], true, (sfVector2i){7, 1}, heros_sprite);
    effect_tab[3] = NULL;
    return (effect_tab);
}

heros_t *init_heros(sfTexture **text_tab)
{
    heros_t *heros = malloc(sizeof(heros_t));
    sfFloatRect hitbox = {30, 25, 55, 55};
    sfFloatRect colbox = {40, 60, 80, 90};

    heros->speed = 200.f;
    heros->texture_base = text_tab[KNIGHT_TEXT];
    heros->npc = init_npc(heros->texture_base);
    heros->npc->attack = 10;
    heros->npc->pv = 100;
    heros->npc->entity->parent = heros->npc;
    set_offset(heros->npc->entity, (sfVector2i){6, 8});
    set_action_tab_heros(heros);
    set_attbox_dim_heros(heros->npc);
    heros->npc->entity->effect_tab = create_effect_tab_heros(
        text_tab, heros->npc->entity->sprite);
    heros->inventory = NULL;
    heros->npc->special = HEROS;
    heros->npc->entity->colbox_dim = colbox;
    heros->npc->hitbox_dim = hitbox;
    return heros;
}
