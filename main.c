#include "bmp.h"
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


//wm sign.bmp -text "Hello" -date -color FFFFFE -pos 10 20 -o modsign.bmp


int main(int argc, char *argv[]){

    if (argc < 2) //if there is no input as argument
    {
        fprintf(stderr, "Please, enter arguments with order--->input.bmp -text \"input text\" -date -color \"input color in hex\" -pos x y -o output.bmp\n");
        exit(1);
  	}

    unsigned char * I=read_bmp(argv[1]); // getting pointer of bmp file

    Table* alphabet=create_alphabet(50); // creating morse alphabet

    // getting current time
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    // printf("Current Time : %s\n", time_str); // just for testing 

    // allocating string for keeping input arguments as translation to morse alphabet
    char * morse=(char*)calloc(sizeof(char),500); 
    

   // text and date part
    if(strcmp(argv[2],"-text")==0)// if there is input text
    {
        strcat(morse,convert_to_morse(alphabet,argv[3]));
        
        if(strcmp(argv[4],"-date")==0){// if there is input date command

            strcat(morse,convert_to_morse(alphabet,time_str));
            // printf("morse=%s\n",morse); // just for seeing output of morse function
        }
    }


// for(int i=0;i<argc;i++){
//     printf("%d=>%s\n",i,argv[i]);
// }

   
//writing bmp file into new file


// printf("width:%d,height:%d\n",GetWidth(I),GetHeight(I));// just for testing assistant functions


// printf("%d",Hex_to_RGB(argv[6]));
write_bmp(argv[11],I,morse,stoi(argv[8]),stoi(argv[9]), argv[6]); // putting changed image pointer into new bmp file


//just for testing GetPixel
// //pixel position part
//  if(strcmp(argv[7],"-pos")==0){
//         printf("%d\n",*GetPixel(I,stoi(argv[8]),stoi(argv[9])));
//     }


//for testing if watermark is working properly
// for (int x = 10; x < 55; x++)
// {
//     unsigned char * ptr=GetPixel(I,x,20);

//     printf("x:%d ->r:%d,g:%d, b:%d\n",x,ptr[0],ptr[1],ptr[2]);
// }


return 0;

}