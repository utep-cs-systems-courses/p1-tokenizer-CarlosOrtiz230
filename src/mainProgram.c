#include "stdio.h"
#include <stddef.h>
#include <string.h>
#define MAX_LENGTH 100
#include "tokenizer.h" //calling the functions to tokenize

/* //methods in this file */

/* void tokenizeOption(); */


/* //main program start */
/* int main(void){ */
/*   int desition; */
/*   printf("Hi, welcome to your tokenizer :D \n see the options\n"); */
/*   while(1){ */
/*     getchar(); */
/*     printf("press 1 to tokenize a word\n"); */
/*     printf("press 2 to see your history\n"); */
/*     printf("press 3 to exit the program\n"); */
/*     scanf("%d",&desition); */
/*     //while(getchar() != '\n');   */
/*     switch(desition){ */
/*        case 1: */
/* 	 printf("Tokanize\n"); */
/* 	 tokenizeOption(); */
/* 	 break; */
/*        case 2: */
/* 	 printf("History\n"); */
/*          break; */
/*        case 3: */
/* 	 printf("Leaving the programm\n"); */
/* 	 goto end_of_the_program; */
/*        default: */
/*          printf("this is not a valid option\n"); */
/*          break; */
/*     }//switch case ends */
/*   }//while ends */
/*  end_of_the_program: */
/*   return 0; */
/* }//main ends */


/* void tokenizeOption(){ */
/*   char userInput[10]; */
/*   puts("Enter Your phrase"); */
/*   printf(">"); */
/*   getchar(); // Consume the newline character from the previous input */
/*   userInput[strcspn(userInput, "\n")] = '\0'; */
/*   fgets(userInput,sizeof(userInput), stdin); */
/*   printf("\n REACH HERE :D\n"); */
/*   puts(userInput); */
/*   char** userTokens = tokenize(userInput); */
/*   //print_tokens(userTokens); */
/* } */

int main(){

  puts("print statement 1");
  tokenize("input for the tokenizer");
  puts("print statement 2 after tokenizer is called");
}
