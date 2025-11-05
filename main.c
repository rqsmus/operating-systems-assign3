#include "io.h"
#include "mm.h"

//#define NULL (void*)0

typedef struct Node{
  int value;               
  struct Node *next;      
  struct Node *prev;      
} Node;


typedef struct {
  Node *head;             
  Node *tail;            
} List;


void add_counter(List *collection, int value)
{
  Node *new_node = simple_malloc(sizeof(Node));            
  new_node->value = value;                          
  new_node->next = NULL; 
  new_node->prev = collection->tail;                

  if(collection->tail){                             
    collection->tail->next = new_node;              
  } else {
    collection->head = new_node;                    
  }
  collection->tail = new_node;                      
}

void remove_counter(List *collection)
{
  if (!collection->tail) return;                     

  Node *deleted_node = collection->tail;             
  collection->tail = deleted_node->prev;             

  if (collection->tail) {                            
    collection->tail->next = NULL;                   
  } else {
    collection->head = NULL;                         
  }
  simple_free(deleted_node);                      
}

void print_collection(List *collection)
{
  Node *current = collection->head;                 

  while (current) {                                 
    write_int(current->value);                      
    if (current->next) {                            
      write_char(',');
    }
    current = current->next;                       
    }
    write_char(';');                                
    write_char('\n');                               
}

int
main()
{
  List my_collection = {0};                        
  int counter = 0;                                  

  while(1){                                         
    char current_char = read_char();                

    if(current_char == 'a'){                        
      add_counter(&my_collection, counter);
      counter++;
      continue;

    } else if(current_char == 'b'){                 
      counter++;
      continue;

    } else if(current_char == 'c'){                 
      remove_counter(&my_collection);
      counter++;
      continue;

    } else if(current_char == 'q'){
      char c;                                           
      while ((c = read_char()) != '\n' && c != EOF) { 
      }
      break;

    } else {                                        
      char c;                                           
      while ((c = read_char()) != '\n' && c != EOF) { 

      }
      break;
    }
  }


  print_collection(&my_collection);

  write_char('\n');
  write_string("count = ");
  write_int(counter);
  write_char('\n');

  return 0;
}
