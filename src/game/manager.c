//
// Created by baragouin on 12/05/22.
//

#include <stdlib.h>
#include "manager.h"
#include "event.h"

game_t *game_create(sfRenderWindow *window)
{
    game_t *game = malloc(sizeof(game_t));

    (*game) = (game_t){
        .window = window,
        .events = NULL
    };
    return game;
}

void game_destroy(game_t *game)
{
    events_free(game->events);
    textures_destroy(game->textures);
    sfRenderWindow_destroy(game->window);
    free(game);
}
