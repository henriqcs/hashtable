#include <stdio.h>

#include "hashtable.h"

int
main(int argc, char **argv)
{
	Hashtable ht = ht_create();

	ht_set(ht, "name1", "henrique");
	ht_set(ht, "name2", "juliana");
	ht_set(ht, "name3", "russian");
	ht_set(ht, "name4", "doge");
	ht_set(ht, "name5", "luke");
	ht_set(ht, "name6", "haha");
	ht_set(ht, "name7", "heitor");

	ht_dump(ht);

	printf("key 'name3': %s\n", ht_get(ht, "name3"));

	return 0;
}
