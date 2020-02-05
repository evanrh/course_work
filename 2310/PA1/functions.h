/*******************************
 *Evan Hastings                *
 *CPSC 2310 Spring 2020        *
 *Due Date: 2/15/20            *
 *Instructor: Dr. Yvon Feaster *
 *Lab Time: 3:30               *
 ******************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int num_args_check(int argc);

int valid_nums_check(uint64_t a, uint64_t b);

void inplace_swap(int *a_ptr, int *b_ptr);

void print_table(uint8_t a, uint8_t b);

char* dec2bin(uint8_t num);
