#include <stdlib.h>
#include <stdio.h>

typedef unsigned int WORD;
typedef unsigned char BYTE;

int endian(void)
{
	// Wirte word in memory
	WORD word = 0x22CCDDEE;
	// pointer to byte
	BYTE *byte;

	// cast word pointer to byte pointer
	byte = (BYTE *) &word;

	/*Print memory from left to right
	 *byte[0]byte[1]byte[2]byte[3]
	 *22	CC	DD	EE	Memory with Little Endian
	 *EE	DD	CC	22	Memory with Big Endian
	 */
	// if Byte[0] == 11
	if( byte[0] == ((word >> 0) & 0xFF) )
		printf("Little Endian Architecture\n");
	if( byte[0] == ((word >> 24) & 0xFF) )
		printf("Big Endian Architecture \n");
	return EXIT_SUCCESS;
}

int ex315(void)
{
	return endian();
}
