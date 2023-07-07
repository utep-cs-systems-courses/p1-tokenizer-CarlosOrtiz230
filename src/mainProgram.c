
#include "stdio.h"
#include <stddef.h>
#include <string.h>
#define MAX_LENGTH 100
#include "tokenizer.h"// calling the functions to tokenize
#include "history.h"

//methods in this file

void tokenizeOption(List* history);
void historyOption(List* history);

 /* //main program start */
int main(void){
  int desition;// user desition for the program 
  List*history =  init_history(); //history is declared and  initializated */

  //main menu starts
  printf("\nhi, welcome to your tokenizer :d \n see the options\n");
  while(1){
    getchar();
    printf("\npress 1 to tokenize a word\n");
    printf("press 2 to see your history\n");
    printf("press 3 to exit the program\n");
    scanf("%d",&desition);
    //while(getchar() != '\n');
    switch(desition){
       case 1:
	 printf("--tokanize--\n");
	 tokenizeOption(history);
	 break;
       case 2:
	 printf("\n--history--");
	 historyOption(history);
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
   
  
void tokenizeOption(List* hst){ //tokenizer option calls tokenizer functions and recieve history
  char userInput[MAX_LENGTH];//string with predefined size
  printf("Enter a string:\n> ");
  getchar();//clean scanner
  fgets(userInput,MAX_LENGTH,stdin);
  userInput[MAX_LENGTH - 1] = '\0';
  char* p = userInput; //user phrase
  //tokenizer returns a pointer of pointer
  
  char** userTokens = tokenize(p);
  print_tokens(userTokens);
  puts("\n");
  add_history(hst    , userInput);// add to the history linked list
}//method ends


void historyOption(List* hst){
  int userDesition;
  int specificIndex;
    //loop for the menu
  while(1){
    getchar();
     printf("\nWelcome to the history menu\n");
     printf(">press 1 to see the whole history\n");
     printf(">press 2 to see a specific index history\n");
     printf(">press 3 to go back to the main menu\n");
     printf(">press 4 to clean the history\n");
     scanf("%i",&userDesition);
     switch(userDesition){
       case 1:
         print_history(hst);
	 break;
       case 2:
	 getchar();//clean buffer
	 int maxIndex = sizeHistory(hst);
	 printf("Select your desired Index.(start at 0)\n");
	 scanf("%d",&specificIndex);
	 if(specificIndex>maxIndex){
	   printf("select a valid index, this number is out of index\n");
	   getchar();//clean buffer
	   break;
	 }//else print the specific history
         printf("\n%s\n",get_history(hst,specificIndex));
         break;
       case 3:
	 return; //leave this method
       case 4:
         puts("\nhistory has been cleaned!\n");
         free_history(hst);
         break;       
       default:
	  printf("this is not a valid option please enter a valid input\n ");
	  break;
     }//switch case ends
  }//while ends
}//historyOption ends



