#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

struct Entry {
	char *key;
	char *value;
	Entry next;
};

struct Hashtable {
	Entry *entries;
};

Hashtable
ht_create()
{
	int i;

	Hashtable ht = (Hashtable) malloc(sizeof(struct Hashtable) * 1);
	ht->entries = (Entry *) malloc(sizeof(Entry) * TABLE_SIZE);

	for (i = 0; i < TABLE_SIZE; i++) {
		ht->entries[i] = NULL;
	}

	return ht;
}

void
ht_set(Hashtable ht, const char *key, const char *value)
{
	unsigned int slot = hash(key);
	Entry entry = ht->entries[slot];
	Entry prev;

	if (entry == NULL) {
		ht->entries[slot] = ht_pair(key, value);
		return;
	}

	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0) {
			free(entry->value);
			entry->value = malloc(strlen(value) + 1);
			strcpy(entry->value, value);
			return;
		}

		prev = entry;
		entry = prev->next;
	}

	prev->next = ht_pair(key, value);
}

char *
ht_get(Hashtable ht, const char *key)
{
	unsigned int slot = hash(key);
	Entry entry = ht->entries[slot];

	if (entry == NULL)
		return NULL;

	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0) {
			return entry->value;
		}

		entry = entry->next;
	}

	return NULL;
}

void
ht_dump(Hashtable ht)
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		Entry entry = ht->entries[i];

		if (entry == NULL)
			continue;

		printf("slot[%4d]: ", i);

		while (entry != NULL) {
			printf("%s=%s ", entry->key, entry->value);
			entry = entry->next;
		}

		printf("\n");
	}
}

static unsigned int
hash(const char *key)
{
	unsigned long int value = 0;
	unsigned int i = 0;
	unsigned int key_len = strlen(key);

	for (; i < key_len; i++) {
		value = value * 37 + key[i];
	}

	value = value % TABLE_SIZE;

	return value;
}

static Entry
ht_pair(const char *key, const char *value)
{
	Entry entry = (Entry) malloc(sizeof(Entry) * 1);
	entry->key = (char *) malloc(strlen(key) + 1);
	entry->value = (char *) malloc(strlen(value) + 1);

	strcpy(entry->key, key);
	strcpy(entry->value, value);

	entry->next = NULL;

	return entry;
}
