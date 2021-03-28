#include "lesson9.h"


// [9.1] Priority exclusion queue-------------------------
void insert(int pr, int dat) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->dat = dat;
  node->pr = pr;

  if (items == SZ) {
    printf("%s \n", "Queue is full");
    return;
  } else {
    arr[tail++] = node;
    items++;
  }
}

Node* remove_item() {
  if (items == 0) {
    return NULL;
  } else {
    int idx =0;
    Node *tmp = arr[head];

    for (int i = head; i < tail; ++i) {
      if (arr[i]->pr > tmp->pr) {
        continue;
      } else {
        idx = i;
        tmp = arr[idx];
      }
    }

    printf("Dequeued element: [%d, %d] \n", tmp->pr, tmp->dat);

    for (int i = idx; i < tail - 1; ++i) {
      arr[i] = arr[i + 1];
    }

    items--;
    tail--;

    if (tail < SZ) {
      for (int i = tail; i < SZ; ++i) {
        arr[i] = NULL;
      }
    }

    return tmp;
  }
}
// -------------------------------------------------

// [9.2] To binary using stack
void toBinary(int num) {
  push(num % 2);

  if(num/2 <= 1){
    push(num % 2);
    return;
  }
  else {
    toBinary(num/2);
  }
}

void printBinaryFromStack() {
  if (cursor == -1)
    return;

  for (int i = cursor; i >= 0; --i) {
    printf("%i", Stack[i]);
  }
  printf("\n");
}

// ------------------------------


int main(int argc, char *argv[]) {
  //Stack (Use same stack as 9.2)-------
  /* push('a'); */
  /* push('b'); */
  /* push('c'); */
  /* push('d'); */
  /* push('e'); */
  /* push('f'); */

  /* while (cursor != -1) { */
  /*   printf("%c", pop()); */
  /* } */
  /* printf("\n"); */
  //-------------------------------

  //Queue--------------------------
  /* enqueue('a'); */
  /* enqueue('b'); */
  /* enqueue('c'); */
  /* enqueue('d'); */
  /* enqueue('e'); */
  /* enqueue('f'); */

  /* while (items > 0) { */
  /*   printf("%c", dequeue()); */
  /* } */
  /* printf("\n"); */
  //-------------------------------

  //Priority inclusion queue-------
  /* init(); */

  //-------------------------------

  // [9.1] Priority exclusion queue-------
  init();
  insert(7, 11);
  insert(2, 22);
  insert(1, 33);
  insert(4, 44);
  insert(1, 55);
  insert(6, 66);
  insert(7, 77);
  insert(8, 88);
  insert(9, 99);
  insert(2, 28);
  printQueue();
  remove_item();
  printQueue();
  insert(8, 88);
  printQueue();
  remove_item();
  printQueue();
  remove_item();
  remove_item();
  printQueue();
  //-------------------------------

  // [9.2] To binary using stack
  int num;
  printf("Enter real number: ");
  scanf("%i", &num);
  toBinary(num);
  printBinaryFromStack();

  // ------------------------------
  return 0;
}
