#include "stdio.h"
#include <stddef.h>
#define MAX_LENGTH 100
#include "tokenizer.h"

int main(void){
  int desition;
  printf("Hi, welcome to your tokanizer :D \n see the options\n");
  while(1){
    printf("press 1 to tokanize a word\n");
    printf("press 2 to see your history\n");
    printf("press 3 to exit the program\n");
    scanf("%d",&desition);
    while(getchar() != '\n');  
    switch(desition){
       case 1:
	 printf("Tokanize\n");
	 break;
       case 2:
	 printf("History\n");
         break;
       case 3:
	 printf("Leaving the programm\n");
	 goto end_of_the_program;
       default:
         printf("this is not a valid option");
         break;
    }//switch case ends
  }//while ends
 end_of_the_program:
  return 0;
}//main ends


void tokenizeOption(){
  char userInput[MAX_LENGTH];
  puts("Enter Your phrase");
  printf(">");
  scanf("%s",userInput);
  char** userTokens = tokenize(userInput);
  print_tokens(userTokens);
  

}
