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

int valid_nums_check(int *a, int *b)	{
	unsigned int max = 255;
	unsigned int min = 0;

	while((*a > max || *a < min) && (*b > max || *b < min))	{
		printf("Please enter values for a and b that are between 0 and 255\n");
		printf("Enter two space separated numbers [a b]: ");
		scanf("%d %d",a,b);
	}

	while(*a > max || *a < min) {
		printf("Please enter a value for a between 0 and 255: ");
		scanf("%d",a);
	}

	while(*b > max || *b < min) {
		printf("Please enter a value for b between 0 and 255: ");
		scanf("%d",b);
	}

	return(0);
}

void inplace_swap(int *a_ptr, int *b_ptr)	{

	// Buffers to hold and free binary strings of a and b
	char *a_buffer = dec2bin(*a_ptr);
	char *b_buffer = dec2bin(*b_ptr);

	printf("\n**** Inplace swap ****\n");
	printf("Original: a = %s b = %s\n",a_buffer,b_buffer);

	*b_ptr = *a_ptr ^ *b_ptr;
	free(a_buffer); a_buffer = dec2bin(*a_ptr);
	free(b_buffer); b_buffer = dec2bin(*b_ptr);

	printf("Step 1  : a = %s b = %s\n",a_buffer,b_buffer);
	
	*a_ptr = *a_ptr ^ *b_ptr;
	free(a_buffer); a_buffer = dec2bin(*a_ptr);
	free(b_buffer); b_buffer = dec2bin(*b_ptr);

	printf("Step 2  : a = %s b = %s\n",a_buffer,b_buffer);

	*b_ptr = *a_ptr ^ *b_ptr;
	free(a_buffer); a_buffer = dec2bin(*a_ptr);
	free(b_buffer); b_buffer = dec2bin(*b_ptr);

	printf("Final   : a = %s b = %s\n",a_buffer,b_buffer);

	free(a_buffer);
	free(b_buffer);

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
