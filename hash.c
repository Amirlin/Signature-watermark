#include "hash.h"

Table *new_table(int size)
{
    Table *table = (Table*)malloc(sizeof(Table));
    table->size = size;
    table->slot = (Node**)malloc(sizeof(Node*)*size);
    int i;
    for(i=0; i<size; i++)
        table->slot[i] = NULL;
    return table;
}

int hash_Hash(Table* table,char* key)
{
   
    if (table == NULL || table->size <= 0)
        return -1;
    int index;
    for (index = 0; *key != '\0'; key++)
    {
        index = (index * 256 + (int)(*key)) % table->size;

    }
    return index;
}


void insert_hash(Table *table,char* key,char* val)
{
    int index = hash_Hash(table,key);
    Node *slot = table->slot[index];
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *temp = slot;
    while(temp)
    {
        if(strcmp(temp->key,key)==0)
        {
            temp->val = val;
            return;
        }
        temp = temp->nextNode;
    }
    newNode->key = key;
    // printf("%s\n",newNode->key);
    newNode->val = val;
    newNode->nextNode = slot;
    table->slot[index] = newNode;
}


char* search_key(Table *table,char* key)
{
    int index = hash_Hash(table,key);
    Node *slot = table->slot[index];
    Node *temp = slot;
    while(temp)
    {
        if(strcmp(temp->key,key)==0)
        {
            return temp->val;
        }
        temp = temp->nextNode;
    }
    return NULL;
}


void print_table(Table *table)
{
    int i;
    for (i=0; i<table->size; i++)
    {
        Node *slot = table->slot[i];
        Node *temp = slot;
        while(temp)
        {
            printf("%s ==> %s\n",temp->key,temp->val);
            temp = temp->nextNode;
        }
    }
}

char* itos(int a){
    char* c = calloc(sizeof(char),10);
    sprintf(c,"%d",a);
    return c;
}
int stoi(char *c){
    return (int) strtol(c, (char **)NULL, 10);
}

char * char_to_string(char c){
    char *ch = (char *) malloc(sizeof(char)*2);
        sprintf(ch,"%c",c);
        return ch;
}