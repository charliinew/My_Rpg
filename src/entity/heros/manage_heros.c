/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void recovery_stamina(heros_t *heros, float time)
{
    if (heros->stamina < heros->stamina_max) {
        heros->stamina += heros->stami_per_sec * time;
        if (heros->stamina > heros->stamina_max)
            heros->stamina = heros->stamina_max;
    }
}

void check_level_up(heros_t *heros)
{
    int act = heros->level_act;

    if (heros->npc->xp >= level_tab[heros->level_act].xp_to_reach) {
        heros->level_act += 1;
        heros->npc->xp = 0;
        act++;
        heros->stamina_max = level_tab[act].stamina_max;
        heros->stamina = level_tab[act].stamina_max;
        heros->pv_max = level_tab[act].pv_max;
        heros->npc->pv = level_tab[act].pv_max;
        heros->bar_tab[LIFE_BAR]->max = level_tab[act].pv_max;
        heros->bar_tab[STAMINA_BAR]->max = level_tab[act].stamina_max;
        heros->bar_tab[XP_BAR]->max = level_tab[act].xp_to_reach;
        heros->stami_per_sec = level_tab[act].stami_per_sec;
        heros->npc->attack = level_tab[act].attack;
        heros->npc->entity->effect_tab[LEVEL_UP_HEROS]->active = true;
    }
}

void manage_heros(heros_t *heros, rpg_t *rpg)
{
    manage_movements(rpg);
    manage_heros_attack(heros, rpg->key_state);
    recovery_stamina(heros, rpg->time);
    check_level_up(heros);
}
