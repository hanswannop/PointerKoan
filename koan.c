#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	puts("This is the C++ pointer koan.");
	puts("Meant to practice pointer arithmetic");
	puts("It simply uses assert on a known data structure, and you fill in the rest");

	// Start with operations on an unsigned char - where a char is 1 byte
	unsigned char originalPointer[256];
	for(int i = 0; i < 256; i++)
		originalPointer[i] = i;

	unsigned char *p = originalPointer;

	assert(p[0] == 0); // First number in array is 0
	assert(*p == 0);

	p = p + 3; // Adding 3 bytes to pointer address brings us to char == 3
	assert(*p == 3);

	unsigned char a = *p++; // Dereference and post increment the pointer. !!To increment the contents would be (*p)++!!
	assert(a == 3);
	assert(*p == 4);

	unsigned char b = *(p++); // Dereference (expression evaluation / assignment) still happens before pointer increment, even with the brackets
	assert(b == 4);
	assert(*p == 5);

	unsigned char c = *++p; // Preincrement pointer position and then dereference
	assert(c == 6);
	assert(*p == 6);

	unsigned char *np = p + 3; // add 3 bytes to pointer address, does not modify original pointer value
	assert(*np == 9);
	assert(*p == 6);

	//Let's setup an integer pointer
	unsigned int *intP = (unsigned int*) originalPointer;

	// Hint remember your processors Endianness
	// Also you should probably do these as hex
	assert(*intP == 0x03020100); // 4 bytes for unsigned in means we show first 4 chars, in little endian

	intP = intP + 3;
	assert(*intP == 0x0F0E0D0C); // Advance 12 bytes sizeof(unsigned int) is 4 bytes

	intP = (unsigned int *)((unsigned char *) (intP) + 3);
	assert(*intP == 0x1211100F); // Cast take precedence over add, advance 3 bytes (not 12)

	unsigned int intX = *intP--;
	assert(intX == 0x1211100F); // Post decrement pointer (by 4 bytes)
	assert(*intP == 0x0E0D0C0B);

	unsigned int *subtractedP = intP - 1; // Pointer to position 4 bytes back
	assert(*subtractedP == 0x0A090807);
	assert(intP - subtractedP == 1); // Subtraction of two pointers of same type gives position difference

	// Obscure C trick
	intP = (unsigned int*) originalPointer;
	assert(3[intP] == 0x0F0E0D0C); // Advance three u interger positions... this is super weird syntax :/

	puts("Congrats you did it!  You must know your pointers");
	return 0;
}
