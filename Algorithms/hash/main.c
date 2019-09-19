#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "hashmap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024 * 1024)

typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    int  number;
} data_struct_t;

int main()
{
    int index;
    int error;

    map_t          mymap;
    char           key_string[KEY_MAX_LENGTH];
    data_struct_t* value;

    mymap = hashmap_new();

    for(index = 0; index < KEY_COUNT; index++)
    {
        value = malloc(sizeof(data_struct_t));
        snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
        value->number = index;

        error = hashmap_put(mymap, value->key_string, value);
        assert(error == MAP_OK);
    }

    snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);

    error = hashmap_get(mymap, key_string, (void**)(&value));

    assert(error == MAP_MISSING);

    for(index = 0; index < KEY_COUNT; index++)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);

        error = hashmap_get(mymap, key_string, (void**)(&value));
        assert(error == MAP_MISSING);

        error = hashmap_remove(mymap, key_string);
        assert(error == MAP_OK);

        free(value);
    }
    hashmap_free(mymap);

    return 1;
}
