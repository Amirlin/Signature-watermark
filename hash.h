#ifndef HASH
#define HASH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *key;
    char *val;
    struct node *nextNode;
}Node;

typedef struct table{
    int size;
    Node **slot;
}Table;

Table *new_table(int size);
int hash_Hash(Table *table,char * key);
void insert_hash(Table *table,char * key,char * val);
char * search_key(Table *table,char * key);
void print_table(Table *table);

char * char_to_string(char c);
char* itos(int a);
int stoi(char *c);

#endif