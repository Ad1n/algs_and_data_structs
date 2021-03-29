#ifndef __LESSON10_H_
#define __LESSON10_H_

#include <stdio.h>
#include <stdlib.h>

#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node {
  T dat;
  struct Node *next;
} Node;

// Linked list--------------
typedef struct {
  Node *head;
  int size;
} List;

void init_list(List* lst) {
  lst->head = NULL;
  lst->size =0;
}

void ins(List *lst, T data) {
  Node *new = (Node*) malloc(sizeof(Node*));
  new->dat = data;
  new->next = NULL;

  Node *current = lst->head;
  if (current == NULL) {
    lst->head = new;
    lst->size++;
    return;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new;
    lst->size++;
  }
}

Node* rm(List *lst, T data) {
  Node *current = lst->head;
  Node *parrent = NULL;

  if (current == NULL) {
    return NULL;
  }

  while (current->next != NULL && current->dat != data) {
    parrent = current;
    current = current->next;
  }

  if (current->dat != data) {
    return NULL;
  }

  if (current == lst->head) {
    lst->head = current->next;
    lst->size--;
    return current;
  }

  parrent->next = current->next;
  lst->size--;
  return current;
}

void printNode(Node *n) {
  if (n == NULL) {
    printf("[]");
    return;
  }
  printf("[%d] ", n->dat);
}

void printList(List *lst) {
  Node *current = lst->head;
  if (current == NULL) {
    printNode(current);
  } else {
    do {
      printNode(current);
      current = current->next;
    } while (current != NULL);
  }
  printf(" Size: %d \n", lst->size);
}
//---------------------------

#endif // __LESSON10_H_
