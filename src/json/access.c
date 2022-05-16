/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include "json.h"

static int count_nodes(conststr path)
{
    int count = 1;
    for (int index = 0; path[index]; index++) {
        if (path[index] == '.')
            count++;
    }
    return count;
}

static char **parsing_access(conststr path)
{
    int size_tab = count_nodes(path);
    char **array = malloc(sizeof(char *) * (size_tab + 1));
    int index_tab = 0;

    array[0] = "";
    for (int i = 0; path[i]; i++) {
        if (path[i] == '.') {
            array[++index_tab] = "";
            continue;
        }
        array[index_tab] = strcat(array[index_tab], &(path[i]));
    }
    array[size_tab] = NULL;

    return array;
}

object *access_node(object *parent, conststr path)
{
    object *current = parent;
    char **array = parsing_access(path);

    for (int index = 0; array[index]; index++) {
        while (strcmp(current->key, array[index]) != 0)
            current = current->next;
        if (array[index + 1] != NULL)
            current = current->value->object;
    }
    for (int line = 0; array[line] != NULL; line++)
        free(array[line]);
    free(array);
    return current;
}
