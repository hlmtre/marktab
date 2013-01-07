#ifndef MT_HASH_H
#define MT_HASH_H

#include <stdbool.h>
#include <stddef.h>

#include "mt_string.h"

typedef struct MtHash
{
  struct MtHashElement* buckets;
  size_t size;
  size_t length;

} MtHash;

MtHash* mt_hash_new();

void mt_hash_insert(MtHash* hash, MtString* key, void* value);

bool mt_hash_contains_key(MtHash* hash, MtString* key);

void* mt_hash_search(MtHash* hash, MtString* key);

void mt_hash_remove(MtHash* hash, MtString* key);

void mt_hash_clear(MtHash* hash);
void mt_hash_free(MtHash* hash);

#endif // MT_HASH_H
