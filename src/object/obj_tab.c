/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

/*
    int text_id_front;
    int text_id_back;
    int time_left;
    bool is_pickable;
    bool is_short;
    int multi_speed;
    int multi_live;
    int multi_attack;
    int add_stamina;
    int add_live;
    int add_xp;
    sfVector2i rect_quad;
    sfVector2i offset;
    sfVector2f scale;
    object_usage_t usage;
*/

obj_template_t obj_tab[] = {
    {DEATH_TEXT, -1, -1, false, true, 1, 1, 1, 0, 0, 0,
        (sfVector2i){7, 2}, (sfVector2i){7, 0},
        (sfVector2f){1.f, 1.f}, NO_USAGE},
    {BAG_TEXT, -1, 120, true, false, 1, 1, 1, 0, 0, 0,
        (sfVector2i){7, 1}, (sfVector2i){7, 0},
        (sfVector2f){1.f, 1.f}, NO_USAGE},
    {HEARTH_POTION_TEXT, HEARTH_POTION_TEXT, 120, true, false,
        1, 1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {HELMET_TEXT, HELMET_TEXT, 120, true, false,
        1, 1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE}
};
