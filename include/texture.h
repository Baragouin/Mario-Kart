/*
** EPITECH PROJECT, 2022
** kart
** File description:
** No file there , just an epitech header example
*/

#ifndef TEXTURE_H_
    #define TEXTURE_H_

typedef struct game_s game_t;

typedef struct texture_s {
    sfTexture *texture;
    struct texture_s *next;
} texture_t;

void texture_collect(game_t *game, sfTexture *texture);

void textures_destroy(texture_t *texture);

#endif //TEXTURE_H_
