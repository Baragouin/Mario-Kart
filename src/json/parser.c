/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include "json.h"
#include <stdlib.h>

static void parse_nodes(object *head)
{
    object *node = head;

    while (node != NULL) {
        int index = 0;
        if (node->raw_value[0] == '{') {
            node->value->object = parse_object(node->raw_value);
            node->type = OBJECT;
        }
        if (node->raw_value[0] == '[') {
            node->value->object = parse_array(node->raw_value);
            node->type = ARRAY;
        }
        if (node->raw_value[0] == '"') {
            node->value->string = extract_value(node->raw_value, &index, true);
            node->type = STRING;
        }
        if (is_number(node->raw_value[0])) {
            node->value->number = (float)atoi(node->raw_value);
            node->type = NUMBER;
        }
        node = node->next;
    }
}

static object *default_node(void)
{
    object *node = malloc(sizeof(object));

    node->value = malloc(sizeof(value));
    node->next = NULL;
    node->raw_value = "";
    node->key = "";
    node->type = UNKNOWN;
    return node;
}

void append_node(object **node)
{
    object *next = default_node();

    (*node)->next = next;
    (*node) = next;
}

object *parse_object(conststr json)
{
    if (json[0] != '{')
        return NULL;
    object *head = default_node();
    object *node = head;
    bool first_parsing = true;

    for (int index = 1; json[index] != '}'; index++) {
        if (!first_parsing)
            append_node(&node);
        if (json[index] == ',')
            index++;
        convert_object_data(node, json, &index);
        if (json[index] == '}')
            break;
        first_parsing = false;
    }
    parse_nodes(head);
    return head;
}

object *parse_array(conststr json)
{
    object *head = default_node();
    object *node = head;
    bool first_parsing = true;

    for (int index = 1; json[index] != ']'; index++) {
        if (!first_parsing)
            append_node(&node);
        if (json[index] == ',')
            index++;
        convert_array_data(node, json, &index);
        if (json[index] == ']')
            break;
        first_parsing = false;
    }
    parse_nodes(head);
    return head;
}
