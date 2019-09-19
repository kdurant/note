#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#define MAP_MISSING -3
#define MAP_FULL -2
#define MAP_OMEM -1
#define MAP_OK 0

typedef void* any_t;

typedef int (*PFany)(any_t, any_t);

typedef any_t map_t;

/**
 * @brief 
 *
 * @return 
 */
extern map_t hashmap_new();

/**
 * @brief 
 *
 * @param in
 * @param f
 * @param item
 *
 * @return 
 */
extern int hashmap_iterate(map_t in, PFany f, any_t item);

/**
 * @brief 
 *
 * @param in
 * @param key
 * @param value
 *
 * @return 
 */
extern int hashmap_put(map_t in, char* key, any_t value);

/**
 * @brief 
 *
 * @param in
 * @param key
 * @param arg
 *
 * @return 
 */
extern int hashmap_get(map_t in, char* key, any_t* arg);

/**
 * @brief 
 *
 * @param in
 * @param key
 *
 * @return 
 */
extern int hashmap_remove(map_t in, char* key);

/**
 * @brief 
 *
 * @param in
 * @param arg
 * @param remove
 *
 * @return 
 */
extern int hashmap_get_one(map_t in, any_t* arg, int remove);

/**
 * @brief 
 *
 * @param in
 */
extern void hashmap_free(map_t in);

/**
 * @brief 
 *
 * @param in
 *
 * @return 
 */
extern int haspmap_length(map_t in);

#endif
