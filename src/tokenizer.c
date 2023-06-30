#include "stdio.h"/* for putchar */
#include <stddef.h>
#include <stdlib.h>



/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == ' ' || c =='\t')? 1:0;
}//space char ends


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c == ' ' || c =='\t')? 0:1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  while(non_space_char(*str)){
    str++;
  }//while ends
  return (*str == '\0')? NULL:str;

  
}//mehtod ends

/* returns a pointer terminator char following *token */
char *token_terminator(char *token){
   char* terminator = token;
    while (*terminator != ' ' ||  *terminator != '\0') {
      terminator++;
    }
    return terminator; //reach to the end of the string
}//token terminator ends

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    int count = 0;
    char *token;

    while (1) {
      token = token_start(str);
      if (token == NULL){
	break;
      }
      count++;
      str = token_terminator(token);
    }
    return count;
}//method ends

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newSpace = malloc((len+1)*sizeof(char));
  for(int i = 0; i<(len+1); i++){
    newSpace[i] = inStr[i];
  }
  newSpace[len] ='\0';
  return newSpace;
}//cocpy str

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    int size = count_tokens(str);// tokens ammount
    char  **tokenVector =(char**)malloc((size+1)* sizeof(char*));// array of size+1 so \0 fits
    int i = 0;
    char *token; //create an empty token pointer
    while (*str != '\0') { //while the string is not at 0 str continue
      while (*str == ' ' || *str == '\t') { // while str is not at space or tab
	str++; //move to next char until space delimits token
      }
      if (*str == '\0') {//end of the tokens
	break;
      }
      token = token_start(str); // start tokanzing
      int tokenLength = token_terminator(token) - token;
      tokenVector[i] = (char*)malloc((tokenLength + 1) * sizeof(char));
      char* strCopy = copy_str(tokenVector[i],  tokenLength);
      tokenVector[i][tokenLength] = '\0';//double pointer can be used as double array
      str = token_terminator(token);
      i++;
    }
    tokenVector[i] = NULL;
    return tokenVector;
}//methods ends

/* Prints all tokens. */
void print_tokens(char **tokens){
  for(int i = 0; tokens[i]!="\0";i++){ 
    printf("Token: %s\n",tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  char **token = tokens;
  while (*token != NULL){//traverse to clean individual tokens
    free(*token);
    token++;
  }
  free(tokens);//clean the array
}//method end
