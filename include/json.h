//
// Created by baragouin on 17/05/22.
//

#ifndef JSON_H_
#define JSON_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef const char *conststr;

typedef struct object_t object;

typedef enum {
    STRING, NUMBER, OBJECT, ARRAY, ELEMENT, UNKNOWN
} data_type;

typedef union value_t {
    char *string;
    float number;
    object *object;
    union value_t **array;
    bool boolean;
} value;

typedef struct object_t {
    char *key;
    char *raw_value;
    data_type type;
    value *value;
    object *next;
} object;

// == reader.c ==

object *parse_json_file(conststr path);

// == parser.c ==

object *parse_object(conststr json);

object *parse_array(conststr json);

// == extractor.c ==

char *extract_value(conststr json, int *index, bool parsing);

char *extract_object(conststr json, int *position);

char *extract_array(conststr json, int *position);

// == convertor.c ==

void convert_object_data(object *node, conststr json, int *index);

void convert_array_data(object *node, conststr json, int *index);

bool is_number(char character);

// == printer.c ==

void print_json(object *json, int level);

// == access.c ==

object *access_node(object *parent, conststr path);

#endif //JSON_H_
