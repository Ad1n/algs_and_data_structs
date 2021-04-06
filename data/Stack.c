#include <stdio.h>
#include "Stack.h"

bool pushStack(Stack* StackToPushInto, T data) {
    if (StackToPushInto->cursor < STACK_MAX_SIZE) {
        StackToPushInto->cursor++;
        StackToPushInto->StackArray[StackToPushInto->cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack(Stack* StackToPopFrom) {
    if (StackToPopFrom->cursor != -1) {
        const int PoppedElementIndex = StackToPopFrom->cursor;
        StackToPopFrom->cursor--;
        return StackToPopFrom->StackArray[PoppedElementIndex];        
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}