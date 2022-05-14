//
// Created by baragouin on 12/05/22.
//

#ifndef MANAGER_H_
    #define MANAGER_H_

    #include <SFML/Graphics.h>

    #define TITLE "MarioKart"
    #define FRAMERATE 60
    #define NEW_WINDOW sfRenderWindow_create

    #include "texture.h"

typedef struct event_s event_t;

typedef struct game_s {
    sfRenderWindow *window;
    event_t *events;
    texture_t *textures;
} game_t;

// == game.c ==

game_t *game_create(sfRenderWindow *window);

void game_destroy(game_t *game);

// == loop.c ==

void game_start(sfRenderWindow *window, game_t *game);

#endif //MANAGER_H_
