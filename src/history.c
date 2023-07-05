
#include "stdio.h"/* for putchar */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

/* initialize the linked list to keep the history. */

List* init_history(){
  List* myHistory = malloc(sizeof(List));
  myHistory -> root = NULL;//initialized
  return  myHistory;
}//init history ends

/* add a history item to the end of the list.
   list* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *temp = list -> root;
  int  counter = 0;//keep a a number
  Item* newItem = malloc(sizeof(Item));
  if(temp == NULL){ //if temp is empty, item becomes the root
    newItem = newItem;
    newItem -> id = counter;
    newItem -> str = str;
    list -> root = newItem
     return;
  }

  while(temp != NULL ){
    temp = temp -> next;
    counter++;
 }
  temp = newItem; 
  temp->id = counter;
  temp->str = str;
  temp->next = NULL;
}//add history ends

/* retrieve the string stored in the node where item->id == id.
   list* list - the linked list
   int id - the id of the item to find */
char *get_history(List *list, int id){
  Item  *temp  = list -> root;
  int counter = 0;
  while(temp!=NULL){
    counter++;
    temp++;
    if(counter == id){
      return temp -> str;
    }
  }
  return NULL;
}//get char ends

/*print the entire contents of the list. */
void print_history(List *list){
  Item *temp = list -> root;
  int counter = 0;
  while(temp!=NULL){
    char* word = get_history(list,counter);
    printf("Element number %d in the history is the word %s\n",counter,word);
    temp++;
    counter++;
  }
}//print history ends


/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *current = list->root;
  Item *next;
  while (current != NULL) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  list->root = NULL;
}



