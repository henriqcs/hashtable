#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define TABLE_SIZE 100000

typedef struct Hashtable * Hashtable;
typedef struct Entry * Entry;

Hashtable ht_create(void);
void ht_set(Hashtable ht, const char *key, const char *value);
char * ht_get(Hashtable ht, const char *key);
void ht_dump(Hashtable ht);

static unsigned int hash(const char *key);
static Entry ht_pair(const char *key, const char *value);

#endif
