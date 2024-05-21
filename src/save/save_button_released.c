/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void appli_save_skill(rpg_t *rpg, save_data_t *save)
{
    for (int i = 0; i < 3; i++)
        rpg->heros->skill->skill_level[i] = save->skill_level[i];
    rpg->heros->skill->skill_tab[RUN] = &(run_tab[save->skill_level[RUN]]);
    rpg->heros->skill->skill_tab[FIRE_BALL] =
        &(fireball_tab[save->skill_level[FIRE_BALL]]);
    rpg->heros->skill->skill_tab[SHIELD] =
        &(shield_tab[save->skill_level[SHIELD]]);
    rpg->heros->skill_point = save->skill_point;
    rpg->heros->skill->act_skill = save->act_skill;
    rpg->heros->npc->entity->effect_tab[SHIELD_HEROS]->active =
        shield_tab[save->skill_level[SHIELD]].active;
}

void appli_save(rpg_t *rpg, save_data_t *save)
{
    rpg->heros->npc->pv = save->heros_pv;
    rpg->heros->stamina = save->heros_stami;
    rpg->heros->npc->xp = save->heros_xp;
    rpg->heros->level_act = save->level_heros;
    rpg->heros->stamina_max = level_tab[save->level_heros].stamina_max;
    rpg->heros->pv_max = level_tab[save->level_heros].pv_max;
    rpg->heros->npc->attack = level_tab[save->level_heros].attack;
    rpg->heros->npc->entity->pos = (sfVector2f){save->x_heros, save->y_heros};
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->heros->npc->entity->pos);
    rpg->heros->bar_tab[LIFE_BAR]->max = level_tab[save->level_heros].pv_max;
    rpg->heros->bar_tab[STAMINA_BAR]->max =
        level_tab[save->level_heros].stamina_max;
    rpg->heros->bar_tab[XP_BAR]->max =
        level_tab[save->level_heros].xp_to_reach;
    appli_save_skill(rpg, save);
    remake_bot_list(save, rpg);
    appli_save_quest(rpg, save);
}

void save_button_released(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)(data);
    save_t *save = (save_t *)(button->child);

    appli_save(rpg, save->data);
    rpg->end->active = 0;
    set_view(rpg,
    rpg->heros->npc->entity->sprite,
    rpg->biome[save->data->id_biome]->back->sprite.sprite);
    rpg->scene = save->data->id_biome;
}
