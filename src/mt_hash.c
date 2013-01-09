#include "mt_hash.h"

#include <assert.h>
#include <stdlib.h>

// An implementation of the murmur hash algorithm
// http://code.google.com/p/smhasher/wiki/MurmurHash3
// This is, for the most part, borrowed from the the HKL language
// See https://github.com/hkl/hkl
static size_t Murmur3(const char* key, size_t len)
{
  
  #define mmix3(h,k) { \
    k *= m1; k = (k<<r1)|(k>>(sizeof(size_t)*8-r1)); \
    k *= m2; h *= 3; h ^= k; \
  }

  const size_t seed = 0xDEADBEEF;
  const size_t m1 = 0x0acffe3d, m2 = 0x0e4ef5f3, m3 = 0xa729a897;
  const size_t r1 = 11, r2 = 18, r3 = 18;

  size_t h = len + seed, k = 0;

  const size_t* dwords = (const size_t*) key;

  while(len >= sizeof(size_t))
  {
    k = *dwords++;
    mmix3(h,k);
    len -= sizeof(size_t);
  }

  const char* tail = (const char*) dwords;

  switch(len)
  {
    case 3: k ^= tail[2] << 16;
    case 2: k ^= tail[1] << 8;
    case 1:
      k ^= tail[0];
      mmix3(h,k);
  }

  h ^= h >> r2;
  h *= m3;
  h ^= h >> r3;

  return h;
}


//
// MtHashObject
//

typedef struct MtHashObject
{
  bool is_tree;
  void* data;
} MtHashObject;

MtHashObject* mt_hash_object_new()
{
  MtHashObject* object = (MtHashObject *) malloc(sizeof(MtHashObject));
  assert(object != NULL);
  
  object->is_tree = false;
  object->data = NULL;

  return object;
}

void mt_hash_object_free(MtHash* hash)
{
  assert(hash != NULL);
  free(hash);
}


//
// MtHash
//

MtHash* mt_hash_new()
{
  MtHash* hash = (MtHash *) malloc(sizeof(MtHash));
  assert(hash != NULL);

  hash->size = 16;
  hash->length = 0;

  return hash;
}

void mt_hash_insert(MtHash* hash, MtString* key, void* value)
{
  assert(hash != NULL);
  assert(key != NULL);
  assert(value != NULL);

}

bool mt_hash_contains_key(MtHash* hash, MtString* key)
{
  assert(hash != NULL);
  assert(key != NULL);

  // TODO: fix
  return false;
}

void* mt_hash_search(MtHash* hash, MtString* key)
{
  assert(hash != NULL);
  assert(key != NULL);

  // TODO: fix
  return NULL;
}

void mt_hash_remove(MtHash* hash, MtString* key)
{
  assert(hash != NULL);
  assert(key != NULL);

}

void mt_hash_clear(MtHash* hash)
{
  assert(hash != NULL);
}

void mt_hash_free(MtHash* hash)
{
  assert(hash != NULL);
}
