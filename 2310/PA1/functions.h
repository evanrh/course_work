/*******************************
 *Evan Hastings                *
 *CPSC 2310 Spring 2020        *
 *Due Date: 2/15/20            *
 *Instructor: Dr. Yvon Feaster *
 *Lab Time: 3:30               *
 ******************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* Parameters: argc - int of number of arguements passed in on command line
 *
 * Return:     argc != 2
 *	This function returns whether the correct number of args are passed
 *	to the program
 */
int num_args_check(int argc);


/* Parameters: a - the reference of the first value passed in 
 *	                on command line
 *             b - the reference of the second value passed in
 *                 on the command line
 *
 * Return: none
 * This function checks if both numbers are within the bounds of
 * uint_8 and allows the user to correct them if they are not
 */
void valid_nums_check(int *a, int *b);


/* Parameters: a_ptr - the reference of the first value passed in 
 * 					on the command line
 *             b_ptr - the reference of the second value passed in 
 *             	on the command line
 *
 * Return: none
 * This function swaps two ints inplace using bitwise XOR
 * uint_8 
 */
void inplace_swap(int *a_ptr, int *b_ptr);


/* Parameters: a - the first value passed in on command line
 *             b - the second value passed in on the command line
 *
 * Return: none
 * This function prints a table of a and b showing
 * their decimal, hexadecimal, and binary representations
 * uint_8 
 */
void print_table(uint8_t a, uint8_t b);


/* Parameters: num - int to be converted to its binary string format
 *
 * Return: a string of the binary representation of num
 * This function converts num into its respective binary format and returns it
 * as a dynamically allocated string
 * uint_8 
 */
char* dec2bin(uint8_t num);

#endif
