#include "lesson10.h"

typedef struct {
  Node *head;
  int size;
} Stack;

void init(Stack *stack) {
  stack->head = NULL;
  stack->size = 0;
}

boolean push(Stack *stack, T value) {
  Node *tmp = (Node*) malloc(sizeof(Node));

  if (tmp == NULL) {
    printf("Stack overflow\n");
    return false;
  }

  tmp->dat = value;
  tmp->next = stack->head;

  stack->head = tmp;
  stack->size++;
  return true;
}

T pop(Stack *stack) {
  if (stack->size == 0) {
    printf("Stack is empty \n");
    return -1;
  }

  Node *tmp = stack->head;
  T data = stack->head->dat;
  stack->head = stack->head->next;
  free(tmp);
  stack->size--;
  return data;
}

void printOneLinkCharNode(Node *n){
  if (n == NULL) {
    printf("[]");
    return;
  }
  printf("[%c]", n->dat);
}

void printOneLinkCharStack(Stack *stack) {
  Node *current = stack->head;
  if (current == NULL) {
    printOneLinkCharNode(current);
  } else {
    do {
      printOneLinkCharNode(current);
      current = current->next;
    } while (current != NULL);
  }
  printf(" Size: %d \n", stack->size);
}

//10.1 Parenthesis
#define OPEN_PARENTHESIS_WEIGHT 1
#define CLOSE_PARENTHESIS_WEIGHT -1

typedef struct Parentheses {
  char open;
  char close;
} Parentheses;

boolean checkParentheses(char* arr, const int size) {
  if (size == 0) {
    printf("Empty input\n");
    return true;
  }

  Parentheses round;
  round.open = '(';
  round.close = ')';

  Parentheses square;
  square.open = '[';
  square.close = ']';

  Parentheses braces;
  braces.open = '{';
  braces.close = '}';

  int weight = 0;

  for (int i = 0; i < size; ++i) {
    if (i != 0) {
      if (arr[i] == round.close) {
        if (arr[i - 1] != round.open)
          return false;
      }

      if (arr[i] == square.close) {
        if (arr[i - 1] != square.open)
          return false;
      }

      if (arr[i] == braces.close) {
        if (arr[i - 1] != braces.open)
          return false;
      }
    }

    if ((arr[i] == round.open) || (arr[i] == square.open) || (arr[i] == braces.open))
      weight++;
    else
      weight--;

    if (weight < 0)
      return false;
  }
  return weight == 0;
}
//-----------------

// Linked list dup-----------------
List* list_copy(List *lst) {
  List *tmp = (List*) malloc(sizeof(List*));
  Node *current_node = (Node*) malloc(sizeof(Node*));

  if (lst->size == 0) {
    init_list(tmp);
    return tmp;
  }

  current_node = lst->head;

  for (int i = 0; i < lst->size; ++i) {
    ins(tmp, current_node->dat);
    current_node = current_node->next;
  }
  free(current_node);

  return tmp;
}
//---------------------------------

// Linked list sort?-----------------
boolean isSorted(List *lst) {
  if (lst->size == 0) {
    return -1;
  }

  Node *current_node = (Node*) malloc(sizeof(Node*));
  current_node = lst->head;

  if (current_node->next == NULL) {
    free(current_node);
    return true;
  }

  for (int i = 0; i < lst->size - 1; ++i) {
    if (current_node->dat > current_node->next->dat) {
      free(current_node);
      return false;
    }
  }
  free(current_node);
  return true;
}
//---------------------------------

int main(int argc, char *argv[]) {
  Stack *st = (Stack*) malloc(sizeof(Stack));
  init(st);

  // 10.1 Parentheses
  const int SZ = 6;
  char par[SZ];
  par[0] = '(';
  par[1] = ')';
  par[2] = '[';
  par[3] = '}';
  par[4] = '{';
  par[5] = '}';
  printf("Check parentheses: %i\n", checkParentheses(par, SZ));
  free(st);
  //-----------------

  // 10.2 Linked list dup-------------------
  List *lst = (List*) malloc(sizeof(List*));
  List *lst_copy;

  init_list(lst);
  printList(lst);
  ins(lst, 1);
  ins(lst, 22);
  ins(lst, 10);
  ins(lst, 12);
  printList(lst);

  lst_copy = list_copy(lst);
  printList(lst_copy);

  rm(lst, 1);
  printList(lst);
  printList(lst_copy);
  //-----------------------------------------

  // 10.3 Linked list sort-------------------
  printf("Sorted ? [ %d ]", isSorted(lst));
  free(lst);
  free(lst_copy);
  // ----------------------------------------

  return 0;
}
