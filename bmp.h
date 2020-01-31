#ifndef BMP
#define BMP
#include "morse.h"
#include <math.h>

typedef struct pixel{
    unsigned char r, g,b;
}pixel;

//  unsigned char* new_bmp(unsigned int width, int height, unsigned int f);
 unsigned char * read_bmp(const char* filename);
 int write_bmp (const char * filename,  unsigned char * I,char *morse,int x,int y,char* color);
//  unsigned char* copy_bmp(unsigned char *Source_I, unsigned char *Dest_I, int width,int height);
 unsigned char* Change_image(unsigned char* I,char *morse,int x,int y,char* color);
 //Assistant functions
unsigned int GetWidth(const unsigned char* I);
int GetHeight(const unsigned char* I);
unsigned int GetSize(const unsigned char* I);
unsigned char* GetPixel(unsigned char* I,unsigned int i,unsigned int j);
struct pixel Hex_to_RGB(char * color);

#endif