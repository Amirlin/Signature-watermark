#ifndef MORSE
#define MORSE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Table* create_alphabet(int size); // creating dictionary
char* convert_to_morse(Table* alphabet,char* c);// translating string to morse code



#endif