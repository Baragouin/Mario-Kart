//
// Created by baragouin on 15/05/22.
//

#ifndef EVENT_H_
    #define EVENT_H_

    #include "manager.h"

typedef void (*callback)(game_t *, sfEvent);

typedef struct event_s {
    sfEventType type;
    struct event_s *next;

    callback action;
} event_t;

// == manager.c ==

void event_register(game_t *game, sfEventType type, callback action);

void events_free(event_t *event);

void events_trigger(game_t *game);

// == window.c ==

void window_close(game_t *game, sfEvent event);

#endif //EVENT_H_
