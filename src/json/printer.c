/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include "json.h"
#include <stdlib.h>

static void print_tabulations(int level)
{
    for (int tab = 0; tab < level; tab++)
        printf("  ");
}

void print_json(object *json, int level)
{
    if (json == NULL)
        return;
    print_tabulations(level);
    printf("%s = ", json->key);
    switch (json->type) {
        case STRING:
            puts(json->value->string);
            break;
        case NUMBER:
            printf("%d\n", (int)json->value->number);
            break;
        case OBJECT:
        case ARRAY:
            puts(json->type == OBJECT ? "{\n" : "[");
            print_json(json->value->object, level + 1);
            print_tabulations(level);
            puts(json->type == OBJECT ? "}\n" : "]");
            break;
        default:
            break;
    }
    print_json(json->next, level);
}
