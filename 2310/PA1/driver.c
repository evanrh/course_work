/*******************************
 *Evan Hastings                *
 *CPSC 2310 Spring 2020        *
 *Due Date: 2/15/20            *
 *Instructor: Dr. Yvon Feaster *
 *Lab Time: 3:30               *
 ******************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "functions.h"

int main(int argc, char* argv[])	{

	// Correct number of args check
	if(num_args_check(argc))	{
		printf("Usage: <Value of a> <Value of b>\n");
		exit(1);
	}

	// Convert strings to int
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	// Check for nums within bounds
	valid_nums_check(&a,&b);

	print_table(a,b);
	inplace_swap(&a, &b);
	print_table(a,b);

	return 0;
}
