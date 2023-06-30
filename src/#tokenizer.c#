#ifndef _TOKENIZER_
#define _TOKENIZER_

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
  str++;
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
      *token = token_start(str);
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
  newSpace[len] = "\0";
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
  int size = count_tokens(str);
  char  **tokenVector =(char**)malloc(size * sizeof(char*));
  tokenVector[size+1] = '\0'; 
  char **token;
  for(int i = 0; i<size; i++){
    while(*str!='\0'){
      token = 
    }//while ends
    tokenVector[i] = 
  }
  tokenVector[size] = '\0';
  return tokenVector;
  
}//methods ends

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
