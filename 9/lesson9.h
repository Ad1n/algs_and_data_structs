#ifndef __LESSON9_H_
#define __LESSON9_H_
#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

#define SZ 10

typedef  int boolean;

//Stack----------------------------------
int cursor = -1;
T Stack[SIZE];

boolean push(T data) {
  if (cursor < SIZE) {
    Stack[++cursor] =  data;
    return true;
  } else {
    printf("%s \n", "Stack overflow");
    return false;
  }
}

T pop() {
  if (cursor != -1) {
    return Stack[cursor--];
  } else {
    printf("%s \n", "Stack is empty");
    return -1;
  }
}
//---------------------------------------

//Queue----------------------------------
T Queue[SIZE];

int first = 0;
int end = -1;
int items = 0;

boolean enqueue(T data) {
  if (items == SIZE) {
    printf("%s \n", "Queue is full");
    return false;
  }

  if (end == SIZE - 1)  {
    end = -1;
  }

  Queue[++end] = data;
  items++;
  return true;
}

T dequeue() {
  if (items == 0) {
    printf("%s \n", "Queue is empty");
    return -1;
  } else {
    int tmp = Queue[first++];
    first %= SIZE; //if (first == SIZE) first = 0
    items--;
    return tmp;
  }
}
//---------------------------------------

// Priority inclusion queue-------------------------
typedef struct {
  int pr;
  int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
  for (int i = 0; i < SZ; ++i) {
    arr[i] = NULL;
  }
  head = 0;
  tail = 0;
  items = 0;
}

void ins(int pr, int dat) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->dat = dat;
  node->pr = pr;
  int flag;

  if (items == 0) {
    arr[tail++] = node;
    items++;
  } else if (items == SZ) {
    printf("%s \n", "Queue is full");
    return;
  } else {
    int i = 0;
    int idx = 0;
    Node *tmp;

    for (int i = head; i < tail; ++i) {
      idx = i % SZ;
      if (arr[idx]->pr > pr) {
        break;
      } else {
        idx++;
      }
    }
    flag = idx % SZ;
    i++;
    while (i < tail) {
      idx = i % SZ;
      tmp = arr[idx];
      arr[idx] = arr[flag];
      arr[flag] = tmp;
      i++;
    }
    arr[flag] = node;
    items++;
    tail++;
  }
}

Node* rem() {
  if (items == 0) {
    return NULL;
  } else {
    int idx = head++ % SZ;
    Node *tmp = arr[idx];
    arr[idx] = NULL;
    items--;
    return tmp;
  }
}

void printQueue() {
  printf("[ ");
  for (int i =0; i < SZ; ++i) {
    if (arr[i] == NULL) {
      printf("[*, *] ");
    } else {
      printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
  }
  printf("]\n");
}
//---------------------------------------

#endif // __LESSON9_H_
