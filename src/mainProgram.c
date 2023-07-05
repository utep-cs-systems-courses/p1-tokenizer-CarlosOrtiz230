
#include "stdio.h"
#include <stddef.h>
#include <string.h>
#define MAX_LENGTH 100
#include "tokenizer.h"// calling the functions to tokenize
#include "history.h"

//methods in this file

void tokenizeOption();

//main program start
int main(void){
  int desition;// user desition for the program
  List history =  init_history(); //history is declared and  initializated
  
  printf("hi, welcome to your tokenizer :d \n see the options\n");
  while(1){
    getchar();
    printf("press 1 to tokenize a word\n");
    printf("press 2 to see your history\n");
    printf("press 3 to exit the program\n");
    scanf("%d",&desition);
    //while(getchar() != '\n');
    switch(desition){
       case 1:
	 printf("tokanize\n");
	 tokenizeOption(history);
	 break;
       case 2:
	 printf("history\n");
         break;
       case 3:
	 printf("leaving the programm\n");
	 goto end_of_the_program;
       default:
         printf("this is not a valid option\n");
         break;
    }//switch case ends
  }//while ends
 end_of_the_program:
   return 0;
}//main ends
  
  
void tokenizeOption(List hst){ //tokenizer option calls tokenizer functions and recieve history 
  char userInput[MAX_LENGTH];
  printf("Enter a string:\n> ");
  getchar();
  fgets(userInput,MAX_LENGTH,stdin);
  userInput[MAX_LENGTH - 1] = '\0';
  char* p = userInput;;
  char** userTokens = tokenize(p);
  print_tokens(userTokens);
  add_history(hst, userTokens);
  print_history(hst);
}
  
 
