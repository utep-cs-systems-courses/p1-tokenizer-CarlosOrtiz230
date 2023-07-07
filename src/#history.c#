
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
  if (list == NULL) {
    printf("Error: Invalid list\n");
    return;
  }
  //creating new item
  Item* newItem = malloc(sizeof(Item));
  if (newItem == NULL) {
    printf("Error: Memory allocation failed\n");
    return;
  }
  //assign of memory for the word and the copy
  newItem->str = malloc(strlen(str) + 1);
  if (newItem->str == NULL) {

    printf("Error: Memory allocation failed\n");
    free(newItem);
    return;
  }
  strcpy(newItem->str, str);
  newItem -> next = NULL;

  if(list ->root ==NULL){
    newItem->id = 0;
    list->root = newItem;
    printf("\nThe word '%s' is added as the root: '%s'\n", newItem->str, list->root->str);
    return;
  }

  //find the last element of the list
  Item* temp = list->root;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  //add the new element to the end of the list
  temp->next = newItem;
  newItem->id = temp->id + 1; // Establecer el id del nuevo elemento
  printf("\nThe word '%s' is added to the history\n", newItem->str);
  return;
}//add history ends
 

/* retrieve othe string stored in the node where item->id == id.
   list* list - the linked list
   int id - the id of the item to find */

char *get_history(List *list, int id){
  Item  *temp  = list -> root;
  int counter = 0;
  while(temp!=NULL){
    if(counter == id){ //if you find the desired item return it 
      return temp -> str;
    }
    counter++;
    temp = temp -> next; 
  }
  
  return NULL;
}//get char ends

/*print the entire contents of the list. */
void print_history(List *list){
  Item *temp = list->root;
  int counter = 0;
  // Recorrer la lista para imprimir su contenido
  while (temp != NULL) {
    if (temp->str != NULL) {
      printf("Element number %d in the history is the word %s\n", counter, temp->str);
    } else {
      printf("Element number %d in the history does not have a word associated\n", counter);
    }
    temp = temp->next;
    counter++;

  }
}//print history ends


/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *current = list->root;
  Item *next;
  //traveerse the list to earse everything
  while (current != NULL) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  list->root = NULL;
}

int sizeHistory(List* hst){
  Item *temp = hst -> root;
  int counter = 0;
  ///travers elinked list to print it
  while(temp!=NULL){
    temp = temp -> next;
    counter++;
  }
  return counter;
}


