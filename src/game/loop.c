/*
** EPITECH PROJECT, 2022
** kart
** File description:
** No file there , just an epitech header example
*/

#include "manager.h"
#include "event.h"

static void game_loop(sfRenderWindow *window, game_t *game)
{

}

static void register_events(game_t *game)
{
    event_register(game, sfEvtClosed, &window_close);
}

void game_start(sfRenderWindow *window, game_t *game)
{
    register_events(game);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        events_trigger(game);
        game_loop(window, game);
        sfRenderWindow_display(window);
    }
}
