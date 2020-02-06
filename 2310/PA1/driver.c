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

	if(num_args_check(argc))	{
		printf("Usage: <Value of a> <Value of b>\n");
		exit(1);
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	valid_nums_check(&a,&b);

	/*if(valid_nums_check(a,b))	{
		fprintf(stderr,"Error! Values of a and b must be between 0 and 255\n");
		exit(1);
	}*/

	print_table(a,b);
	inplace_swap(&a, &b);
	print_table(a,b);

	return 0;
}
