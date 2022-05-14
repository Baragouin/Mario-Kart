/*
** EPITECH PROJECT, 2022
** kart
** File description:
** No file there , just an epitech header example
*/

#include "manager.h"
#include <stdlib.h>

void texture_collect(game_t *game, sfTexture *texture)
{
    texture_t *element = malloc(sizeof(texture_t));
    texture_t *current = game->textures;

    element->texture = texture;
    element->next = NULL;
    if (current == NULL) {
        game->textures = element;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = element;
    }
}

void textures_destroy(texture_t *texture)
{
    if (texture == NULL)
        return;
    sfTexture_destroy(texture->texture);
    textures_destroy(texture->next);
    free(texture);
}
