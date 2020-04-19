#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // number of compared strings

int cmp_str(const void *s1, const void *s2)
{
	return (strcmp(*(char **)s1, *(char **)s2));
}

int bsearchf(void)
{
	char *data[MAX], buffer[80], *ptr, *key_ptr, **key_ptrptr;
	int count;

	// input word
	fprintf(stdout, "Insert %d words\n", MAX);
	for(count=0; count < MAX; count++)
	{
		fprintf(stdout, "Word %d: ", count+1);
		fgets(buffer, 80, stdin);
		// Reserve memory for word number
		data[count]=(char *) malloc(strlen(buffer)+1);
		strcpy( data[count], strtok(buffer,"\n") );
	}
	// sort the single words
	qsort(data, MAX, sizeof(data[0]), cmp_str);
	// print sorted data
	for(count=0; count < MAX; count++)
		fprintf(stdout, "\n Word %d: %s", count+1, data[count]);

	//search for a word
	fprintf(stdout, "\n\n Whats the word you looking for? :>");
	fgets(buffer, 80, stdin);
	/* to search give buffer to key
	 * then zou need annother point which
	 * is pointing to search-key
	 */
	key_ptr = strtok(buffer, "\n");
	key_ptrptr = &key_ptr;
	// Pointer ptr gets adress of search outcome
	ptr = (char *) bsearch(key_ptrptr, data, MAX, sizeof(data[0]), cmp_str);

	if(NULL==ptr)
		fprintf(stdout, "Nothing compares to %s\n", buffer);
	else
		fprintf(stdout, "%s got found \n", buffer);
	return EXIT_SUCCESS;
}

int ex69(void)
{
	return bsearchf();
}
