/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include "json.h"

static char *extract(conststr pattern, int index, int length)
{
    char *place_holder = malloc(sizeof(char) * (length + 1));

    for (int position = 0; position < length; position++)
        place_holder[position] = pattern[index + position];
    place_holder[length] = '\0';
    return place_holder;
}

static int element_length(conststr json, int position, char open, char close)
{
    int objects = 0;
    int index;
    if (json[position] != open)
        return 0;
    for (index = position + 1; json[index] != '\0'; index++) {
        char current = json[index];
        if (current == close && objects == 0)
            break;
        if (current == open)
            objects++;
        else if (current == close)
            objects--;
    }
    return index - position + 1;
}

char *extract_value(conststr json, int *index, bool parsing)
{
    bool number = is_number(json[*index]);
    char *value = (parsing || number ? "" : "\"");
    static conststr string_end = "\"";
    if (json[*index] != '"' && !is_number(json[*index]))
        return "";
    if (json[*index] == '"')
        (*index)++;
    do {
        value = strcat(value, &(json[*index]));
        (*index)++;
    } while (!(json[*index] == '"' || (number && !is_number(json[*index]))));
    if (!parsing && !number)
        value = strcat(value, string_end);
    return value;
}

char *extract_object(conststr json, int *position)
{
    if (json[*position] != '{')
        return "";
    int length = element_length(json, *position, '{', '}');
    char *extracted = extract(json, *position, length);

    (*position) += length;
    return extracted;
}

char *extract_array(conststr json, int *position)
{
    if (json[*position] != '[')
        return "";
    int length = element_length(json, *position, '[', ']');
    char *extracted = extract(json, *position, length);

    (*position) += length;
    return extracted;
}
