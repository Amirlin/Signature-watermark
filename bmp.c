#include "bmp.h"


//  unsigned char* new_bmp(unsigned int width,int height, unsigned int f){// f=0=> fill value(0-black,255->white)
//      unsigned int n=abs(height)*(3*width+width%4);
//      unsigned int N=n+54;
//      unsigned char H[54]={66,77,N,N>>8,N>>24,0,0,0,0,54,0,0,0,40,0,0,0,width,
//                           width>>8,0,0,height,height>>8,height>>16,height>>24,
//                           1,0,24,0,0,0,0,0,n,n>>8,n>>16,n>>24,19,11,0,0,19,11,0,0,
//                           0,0,0,0,0,0,0,0};
     
//      unsigned char * I=(unsigned char*)malloc(sizeof(unsigned char)*N);
//      memcpy(I,H,54);
//      memset(I+54,f,n);
//      return I;

//  }
 

// reading bmp file
// BMP files begin with header information that stores, among other things, the size of the image
// contained in the BMP file. BMP headers store numeric values in little-endian order. Bitwise-shift
// operators can be used to convert to and from little-endian format

 unsigned char * read_bmp(const char* filename){
    FILE * f=fopen(filename,"rb");// file must be opened in binary

    if(!f){
        printf("File could not open\n");
        exit(1);
    }


    unsigned char H[6]; // creating header
    fread(H,1,6,f); 
    rewind(f); // reading beginning of header
    unsigned int N=H[2]+(H[3]<<8)+(H[4]<<24); //getting file size
    unsigned char* I=(unsigned char*)malloc(sizeof(unsigned char)* N); // pointer which will keep address of bmp image
    fread(I,1,N,f);

    return I;
        
}


// putting bmp image into another bmp file
 int write_bmp (const char * filename, unsigned char * I,char *morse,int x,int y,char* color){
     FILE * f=fopen(filename,"wb");

     if(!f){
        printf("File could not open\n");
        exit(1);
    }
    I=Change_image(I,morse,x,y,color);
    unsigned int N=*(I+2)+(*(I+3)<<8)+(*(I+4)<<16)+(*(I+5)<<24);//file size
    unsigned int n=fwrite(I,1,N,f); //write the file
    fclose(f); // and close

    return n; // number of characers that were written to file

 }

 //changing pixels of the image according to morse code
unsigned char * Change_image( unsigned char* I,char *morse,int x,int y,char* color)
 {
    pixel p=Hex_to_RGB(color);
     unsigned char * ptr=malloc(sizeof(unsigned char));
     for (;*morse!='\0';morse++)// until end of string
     {
        ptr= GetPixel(I,x,y);  //pointer to the pixel( 3 byte)
        switch (*morse)
        {
        case '.':
        ptr[0]=p.r;
        ptr[1]=p.g;
        ptr[2]=p.b;
        x=x+2;//1 pixel for dot + 1 pixel for background pixel
            break;
        case '-':
        for (int j = 0; j <3;j++)
        {
            ptr= GetPixel(I,x+j,y);
            ptr[0]= p.r;
            ptr[1]=p.g;
            ptr[2]=p.b;
        }
        x=x+4;//3 pixel for dash + 1 pixel for background pixel
        break;
        case ' ':
        for (int j = 0; j <3;j++)
        {
        ptr= GetPixel(I,x+j,y);
            ptr[0]= p.r;
            ptr[1]=p.g;
            ptr[2]=p.b;
        }
        x=x+3;
        break;
        case '/':
        for (int j = 0; j <5;j++)
        {
            ptr= GetPixel(I,x+j,y);
            ptr[0]= p.r;
            ptr[1]=p.g;
            ptr[2]=p.b;
        }
        x=x+5;
        break;
        default:
            continue;
        }//end of switch 
        
     }
     return I; 
 }



// unsigned char* copy_bmp(unsigned char *Source_I, unsigned char *Dest_I, int width,int height){
// int wd=GetWidth(Dest_I),W=GetWidth(Source_I)+width,hd=abs(GetHeight(Dest_I)),
// H=abs(GetHeight(Source_I))+height,i=width>0?width:0,I=wd<W?wd:W;
// if(i<I)for(unsigned int j=height>0?height:0,J=hd<H?hd:H;j<J;++j)
// memcpy(GetPixel(Dest_I,i,j),GetPixel(Source_I,i-width,j-height),3*(I-i));
// return Dest_I;
// }



// Assistant functions
unsigned int GetWidth(const unsigned char* I){
return *(I+18)+(*(I+19)<<8);
}

 int GetHeight(const unsigned char* I){
return *(I+22)+(*(I+23)<<8)-(*(I+25)==255?65536:0);
}


 unsigned int GetSize(const unsigned char* I){
unsigned int w=GetWidth(I);
return abs(GetHeight(I))*(3*w+w%4);
}

// to get pointer to the pixel in the position of x ->i and y->j
unsigned char* GetPixel(unsigned char* I,unsigned int i,unsigned int j){
return I+54+j*((*(I+18)+(*(I+19)<<8))*3+*(I+18)%4)+3*i;
}

struct pixel Hex_to_RGB(char * color){
       pixel p;
        int r , g, b;
        sscanf(color, "%02x%02x%02x", &r, &g, &b);
        p.r=r;
        p.g=g;
        p.b=b;

        return p;
}







