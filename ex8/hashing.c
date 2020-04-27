#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HASH 10
#define M 31

struct zipc
{
	char city[255];
	unsigned int zip;
	struct zipc *next;
};

struct zipc *hash_table[MAX_HASH];

struct zipc *inserth(char *, unsigned int);
void search_in_hash(char *);
int hash_function(char *);

struct zipc *inserth(char *o, unsigned int p)
{
	struct zipc *pointer;
	// Hash-value (bucket) and hash_adress (0-9)
	int hash_adresses= hash_function(o);

	fprintf(stdout, "Calculated Hash-adress (bucket) %d", hash_adresses);

	// Pointer to, through Hash-function calculated Tableadress 
	pointer = hash_table[hash_adresses];

	// Searching free space for new entry in hash_table[hash_adresses]
	while(pointer != NULL)
	{
		if(strcmp(o, pointer->city) == 0) // Equal City?
			if(pointer->zip == p) // equal zip?
			{
				fprintf(stderr, "%s with ZIP-Code %5u already exists...\n",o,p);
				// avoid double entries
				return pointer;
			}
		pointer=pointer->next;
	}
	// allocate memory for new element
	pointer = malloc(sizeof(struct zipc));
	if(pointer == NULL)
	{
		fprintf(stderr, "No memory available...\n");
		return NULL;
	}
	strcpy(pointer->city, o);
	pointer->zip = p;
	pointer->next = hash_table[hash_adresses] = pointer;
	return pointer;
}

// Function for searching values in hash-table
void search_in_hash(char *o)
{
	struct zipc *pointer;
	// Hash-value (bucket) to hash_adresses (0-9)
	int hash_adresses = hash_function(o);

	fprintf(stdout, "Calculated Hash-adress (bucket) %d", hash_adresses);

	// Pointer to, through Hash-function claculated Tableadress
	pointer = hash_table[hash_adresses];

	// Search for entry in Hash-table
	while(pointer != NULL)
	{
		if(strcmp(pointer->city, o)  == 0)
			fprintf(stdout, "Zip for %s is %d\n",o,pointer->zip);
		pointer=pointer->next;
	}
}

// Hash function to calculate a Hash-value out of a string
int hash_function(char *string)
{
	unsigned int hash_adresses;
	unsigned char *pointer;

	hash_adresses = 0;
	pointer = (unsigned char *) string;
	while(*pointer != '\0')
	{
		hash_adresses = M * hash_adresses + *pointer;
		pointer++;
	}
	return (hash_adresses % MAX_HASH);
}

int hashing(void)
{
	// input
	inserth("Friedberg", 86316);
	inserth("Augsburg" , 86136);
	inserth("Stuttgard", 71345);

	// searching
	search_in_hash("Augsbrug");
	search_in_hash("Friedberg");
	search_in_hash("Stuttgard");
	return EXIT_SUCCESS;
}

int ex811(void)
{
	return hashing();
}
