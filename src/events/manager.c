/*
** EPITECH PROJECT, 2022
** kart
** File description:
** No file there , just an epitech header example
*/

#include <stdlib.h>
#include "event.h"

static void event_append(game_t *game, event_t *to_append)
{
    event_t *current = game->events;

    if (current == NULL) {
        game->events = to_append;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = to_append;
    }
}

static void event_trigger(game_t *game, const event_t *game_event, sfEvent event)
{
    if (game_event->type != event.type || game_event->action == NULL)
        return;
    game_event->action(game, event);
}

void event_register(game_t *game, sfEventType type, callback action)
{
    event_t *event = malloc(sizeof(event_t));

    (*event) = (event_t) {
        .type = type,
        .action = action,
        .next = NULL
    };
    event_append(game, event);
}

void events_free(event_t *event)
{
    if (event == NULL)
        return;
    events_free(event->next);
    free(event);
}

void events_trigger(game_t *game)
{
    static sfEvent event_storage;

    while (sfRenderWindow_pollEvent(game->window, &event_storage)) {
        event_t *event = game->events;
        if (event_storage.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            return;
        }
        while (event != NULL) {
            event_trigger(game, event, event_storage);
            event = event->next;
        }
    }
}
