/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include "json.h"

bool is_number(char character)
{
    return (character >= '0' && character <= '9');
}

void convert_object_data(object *node, conststr json, int *index)
{
    if (json[*index] == '"') {
        for ((*index)++; json[*index] != '"'; (*index)++)
            node->key = strcat(node->key, &(json[*index]));
    }
    (*index) += 2;
    if (json[*index] == '{')
        node->raw_value = extract_object(json, index);
    else if (json[*index] == '"' || is_number(json[*index]))
        node->raw_value = extract_value(json, index, false);
    else
        node->raw_value = extract_array(json, index);
}

void convert_array_data(object *node, conststr json, int *index)
{
    node->key = "";
    if (json[*index] == '{') {
        node->raw_value = extract_object(json, index);
    } else if (json[*index] == '"' || is_number(json[*index]))
        node->raw_value = extract_value(json, index, false);
    else
        node->raw_value = extract_array(json, index);
}
