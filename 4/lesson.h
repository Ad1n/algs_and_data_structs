#ifndef __LESSON_H_
#define __LESSON_H_

#include <stdlib.h>
#include <stdio.h>

char** initArray(char** array, const int row, const int col){
  array = (char**) calloc(sizeof(char*), row);
  for(int i=0; i<row; ++i){
    *(array + i) = (char*) calloc(sizeof(char), col);
  }

  return array;
}

void fill2dIntArray(char** array, const int row, const int col, int border){
  for(int i=0; i<row; ++i){
    for(int j=0; j<col; ++j){
      *((*(array + i)) + j) = rand() % border;
    }
  }
}

void print2dIntArray(char** array, const int row, const int col){
  for(int i=0; i<row; ++i){
    for(int j=0; j<col; ++j){
      printf("%4d", *((*(array + i)) + j));
    }

    printf("\n");
  }
}

void printIntArray(char* array, const int len){
  for(int i=0; i<len; ++i){
      printf("%4d", *(array + i));
  }
}

void swap(char *a, char *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}


#endif // __LESSON_H_
