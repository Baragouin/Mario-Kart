/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** No file there , just an epitech header example
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "json.h"

static long file_size(conststr filepath)
{
    struct stat file_stats;

    if (stat(filepath, &file_stats) != 0)
        return 0;
    return file_stats.st_size;
}

static int minimal_length(conststr string)
{
    int length = 0;
    bool in_string = false;

    for (int index = 0; string[index] != '\0'; index++) {
        char current = string[index];

        if (current == '\n')
            continue;
        if (current == '"') {
            in_string = !in_string;
            length++;
        } else if (current == ' ') {
            length += (in_string ? 1 : 0);
        } else {
            length++;
        }
    }
    return length;
}

char *file_content(conststr file_path)
{
    int file_descriptor;
    long size = file_size(file_path);
    char *content = malloc(sizeof(char) * (size + 1));

    if ((file_descriptor = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "./my_rpg: error opening configuration file\n");
        free(content);
        return NULL;
    }
    if (read(file_descriptor, content, size) == -1) {
        fprintf(stderr, "./tetris: error reading configuration file\n");
        free(content);
        return NULL;
    }
    close(file_descriptor);
    content[size] = '\0';
    return content;
}

char *minimize(conststr string)
{
    int length = minimal_length(string);
    char *result = malloc(sizeof(char) * (length + 1));
    bool in_string = false;
    int position = 0;

    for (int index = 0; string[index] != '\0'; index++) {
        char current = string[index];

        if (current == '\n')
            continue;
        if (current == ' ' && !in_string)
            continue;
        if (current == '"')
            in_string = !in_string;
        result[position++] = current;
    }
    result[length] = '\0';
    return result;
}

object *parse_json_file(conststr path)
{
    char *content = file_content(path);
    if (content == NULL)
        return NULL;
    char *minimized = minimize(content);
    object *json = parse_object(minimized);

    free(minimized);
    free(content);
    return json;
}
