/*******************************
 *Evan Hastings                *
 *CPSC 2310 Spring 2020        *
 *Due Date: 2/15/20            *
 *Instructor: Dr. Yvon Feaster *
 *Lab Time: 3:30               *
 ******************************/
#include "functions.h"

int num_args_check(int argc)	{
	int correct_argc = 3;
	return( argc != correct_argc);
}

int valid_nums_check(uint64_t a, uint64_t b)	{
	return( a > 255 || a < 0 || b > 255 || b < 0);
}

void inplace_swap(int *a_ptr, int *b_ptr)	{
	*b_ptr = *a_ptr ^ *b_ptr;
	*a_ptr = *a_ptr ^ *b_ptr;
	*b_ptr = *a_ptr ^ *b_ptr;
}

void print_table(uint8_t a, uint8_t b)	{

	// dec2bin uses dynamically allocated memory
	// buffers ensure no memory leaks
	char* a_buffer = dec2bin(a);
	char* b_buffer = dec2bin(b);

	printf("\n\tDecimal\t|\tHex\t|\tBinary\n\n");
	printf("a =\t%d\t|\t0x%.2x\t|\t%s\n",a,a,a_buffer);
	printf("b =\t%d\t|\t0x%.2x\t|\t%s\n",b,b,b_buffer);

	free(a_buffer);
	free(b_buffer);
}

char* dec2bin(uint8_t num)	{
	int num_size = 8;

	// String of binary numbers to be output
	char *output = (char*) malloc(sizeof(char) * (num_size + 1));

	// Loop through all possible bits of the num
	for(int i = 0; i < num_size; i++)	{
		
		// Mask to get last bit of the shifted number and make it a char
		output[i] = ((num >> (num_size - (i + 1))) & 0x1) + '0';
	}

	// Null terminate string
	output[num_size + 1] = '\0';

	return output;
}
