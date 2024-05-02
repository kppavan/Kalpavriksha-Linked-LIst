#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining enum for data types
typedef enum
{
  CHAR_TYPE,
  FLOAT_TYPE,
  INT_TYPE,
  STRING_TYPE
} DataType;

// Creating a union to hold different data types
union Data
{
  char char_data;
  float float_data;
  int int_data;
  char *string_data;
};

// Defining the node Structure
typedef struct node
{
  union Data data;
  DataType type;
  struct node *next;
} Node;

// Function to create a new node
Node *create_node(void *value, DataType type)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  new_node->type = type;

  switch (type)
  {
  case CHAR_TYPE:
    new_node->data.char_data = *(char *)value;
    break;
  case FLOAT_TYPE:
    new_node->data.float_data = *(float *)value;
    break;
  case INT_TYPE:
    new_node->data.int_data = *(int *)value;
    break;
  case STRING_TYPE:
    new_node->data.string_data = strdup((char *)value);
    break;
  default:
    printf("Invalid data type.\n");
    free(new_node);
    return NULL;
  }
  new_node->next = NULL;
  return new_node;
}

// Print list
void print_list(Node *head)
{
  Node *current = head;
  printf("Head");
  while (current != NULL)
  {

    switch (current->type)
    {
    case CHAR_TYPE:
      printf("-> %c ", current->data.char_data);
      break;
    case FLOAT_TYPE:
      printf("-> %f", current->data.float_data);
      break;
    case INT_TYPE:
      printf("-> %d", current->data.int_data);
      break;
    case STRING_TYPE:
      printf("-> %s", current->data.string_data);
      break;
    default:
      printf("Unknown data type.\n");
      break;
    }
    current = current->next;
  }
}

int main(void)
{
  Node *head = NULL;

  // Create nodes with different data types
  char char_value = 'A';
  head = create_node(&char_value, CHAR_TYPE);
  float float_value = 6.19;
  head->next = create_node(&float_value, FLOAT_TYPE);
  int int_value = 20;
  head->next->next = create_node(&int_value, INT_TYPE);
  char *string = "Hello Team!";
  head->next->next->next = create_node(string, STRING_TYPE);

  print_list(head);

  return 0;
}
