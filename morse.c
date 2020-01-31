#include "morse.h"

Table* create_alphabet(int size){
 Table* alphabet=new_table(size); 

 insert_hash(alphabet,"A",".- ");     insert_hash(alphabet,"a",".- ");
 insert_hash(alphabet,"B","-... ");   insert_hash(alphabet,"b","-... ");
 insert_hash(alphabet,"C","-.-. ");   insert_hash(alphabet,"c","-.-. "); 
 insert_hash(alphabet,"D","-.. ");    insert_hash(alphabet,"d","-.. ");
 insert_hash(alphabet,"E",". ");      insert_hash(alphabet,"e",". ");
 insert_hash(alphabet,"F","..-. ");   insert_hash(alphabet,"f","..-. ");
 insert_hash(alphabet,"G","--. ");    insert_hash(alphabet,"g","--. ");
 insert_hash(alphabet,"H",".... ");   insert_hash(alphabet,"h",".... ");
 insert_hash(alphabet,"I",".. ");     insert_hash(alphabet,"i",".. ");
 insert_hash(alphabet,"J",".--- ");   insert_hash(alphabet,"j",".--- ");
 insert_hash(alphabet,"L",".-.. ");   insert_hash(alphabet,"l",".-.. ");
 insert_hash(alphabet,"M","-- ");     insert_hash(alphabet,"m","-- ");
 insert_hash(alphabet,"N","-. ");     insert_hash(alphabet,"n","-. ");
 insert_hash(alphabet,"O","--- ");    insert_hash(alphabet,"o","--- ");
 insert_hash(alphabet,"P",".--. ");   insert_hash(alphabet,"p",".--. ");
 insert_hash(alphabet,"Q","--.- ");   insert_hash(alphabet,"q","--.- ");
 insert_hash(alphabet,"R",".-. ");    insert_hash(alphabet,"r",".-. ");
 insert_hash(alphabet,"S","... ");    insert_hash(alphabet,"s","... ");
 insert_hash(alphabet,"T","- ");      insert_hash(alphabet,"t","- ");
 insert_hash(alphabet,"U","..- ");    insert_hash(alphabet,"u","..- ");
 insert_hash(alphabet,"V","...- ");   insert_hash(alphabet,"v","...- ");
 insert_hash(alphabet,"W",".-- ");    insert_hash(alphabet,"w",".-- ");
 insert_hash(alphabet,"X","-..- ");   insert_hash(alphabet,"x","-..- ");
 insert_hash(alphabet,"Y","-.-- ");   insert_hash(alphabet,"y","-.-- ");
 insert_hash(alphabet,"Z","--.. ");   insert_hash(alphabet,"z","--.. ");
 insert_hash(alphabet,"1",".---- ");  insert_hash(alphabet," ","/");
 insert_hash(alphabet,"2","..--- ");
 insert_hash(alphabet,"3","...-- ");
 insert_hash(alphabet,"4","....- ");
 insert_hash(alphabet,"5","..... ");
 insert_hash(alphabet,"6","-.... ");
 insert_hash(alphabet,"7","--... ");
 insert_hash(alphabet,"8","---.. ");
 insert_hash(alphabet,"9","----. ");
 insert_hash(alphabet,"0","----- ");
insert_hash(alphabet,".",".-.-.- ");
 insert_hash(alphabet,",","--..-- ");
 insert_hash(alphabet,":","---... ");
 insert_hash(alphabet,"?","..--.. ");
 insert_hash(alphabet,"'",".----. ");
 insert_hash(alphabet,"-","-....- ");
 insert_hash(alphabet,"/","-..-. ");
 insert_hash(alphabet,"(","-.--.- ");
 insert_hash(alphabet,")","-.--.- ");
 insert_hash(alphabet,"=","-...- ");
 insert_hash(alphabet,"@",".--.-. ");
 insert_hash(alphabet,"\"",".-..-. ");
 return alphabet;


}


char* convert_to_morse(Table* alphabet,char *c){
    char *converted=(char*)calloc(sizeof(char),500);    

    for(;*c!='\0';c++) // until end of string
	{
		strcat(converted,search_key(alphabet,char_to_string(*c)));
	}
    strcat(converted,"/");
    return converted;
}

