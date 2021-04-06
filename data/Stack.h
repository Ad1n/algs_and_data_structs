#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define T char
#define STACK_MAX_SIZE 1000

typedef struct {
    T StackArray[STACK_MAX_SIZE];
    int cursor;
} Stack;

bool pushStack(Stack* StackToPushInto, T data);

T popStack(Stack* StackToPopFrom);

#endif //STACK_H_