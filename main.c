//
// Created by baragouin on 12/05/22.
//

#include "manager.h"
#include "event.h"

static sfRenderWindow *window_create(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NEW_WINDOW(mode, TITLE, sfFullscreen, NULL);

    sfRenderWindow_setFramerateLimit(window, FRAMERATE);
    return window;
}

int main(void)
{
    sfRenderWindow *window = window_create();
    game_t *game = game_create(window);

    game_start(window, game);

    game_destroy(game);
    return 0;
}