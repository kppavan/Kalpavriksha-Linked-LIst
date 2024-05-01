#include <stdio.h>
#include <stdlib.h>

// Creating a node structure
typedef struct node
{
  int data;
  struct node *next;
} Node;

// Fucntion to create a node
Node *create_node(int data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to print linked list
void print_linked_list(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Fucntion to add a node
Node *insert_at_end(Node *head, int data)
{
  if (head == NULL)
  {
    return create_node(data);
  }
  Node *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = create_node(data);
  return head;
}

// Fuction to insert node at beginning
Node *insert_at_beginning(Node *head, int data)
{
  Node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Function to insert at a given position
Node *insert_at_position(Node *head, int data, int position)
{
  if (position < 1)
  {
    printf("Invalid position\n");
    return head;
  }
  if (position == 1)
  {
    return insert_at_beginning(head, data);
  }
  Node *new_node = create_node(data);
  Node *current = head;
  for (int i = 1; i < position - 1 && current != NULL; i++)
  {
    current = current->next;
  }
  if (current == NULL)
  {
    printf("Position out of range\n");
    return head;
  }
  new_node->next = current->next;
  current->next = new_node;
  return head;
}

// Function to delete node at the end of LL
Node *delete_at_end(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return NULL;
  }

  if (head->next == NULL)
  {
    free(head);
    return NULL;
  }

  Node *current = head;
  Node *prev = NULL;
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  free(current);
  return head;
}

// Function to delete a node at beginning
Node *delete_at_beginning(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return NULL;
  }
  Node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Function to delete a node at a given position
Node *delete_at_position(Node *head, int position)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return NULL;
  }
  if (position < 1)
  {
    printf("Invalid position\n");
    return head;
  }
  if (position == 1)
  {
    return delete_at_beginning(head);
  }
  Node *current = head;
  Node *prev = NULL;
  for (int i = 1; i < position && current != NULL; i++)
  {
    prev = current;
    current = current->next;
  }
  if (current == NULL)
  {
    printf("Position out of range\n");
    return head;
  }
  prev->next = current->next;
  free(current);
  return head;
}

int main()
{
  Node *head = NULL;

  // Insertion operations
  head = insert_at_end(head, 10);
  head = insert_at_beginning(head, 30);
  head = insert_at_position(head, 20, 2);
  head = insert_at_end(head, 40);
  print_linked_list(head);

  // Delete operations
  head = delete_at_end(head);
  head = delete_at_beginning(head);
  head = delete_at_position(head, 2);
  print_linked_list(head);
}