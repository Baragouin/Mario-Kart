/*
** EPITECH PROJECT, 2022
** kart
** File description:
** No file there , just an epitech header example
*/

#include "manager.h"

void window_close(game_t *game, sfEvent event)
{
    if (event.type != sfEvtClosed)
        return;
    sfRenderWindow_close(game->window);
}
