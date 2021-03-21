#include "lesson.h"
#include <math.h>

int TBK_ARRAY_SIZE = 11;

void bubbleSort(char* arr, int len){
  for(int i=0; i<len; ++i){
    for(int j=0; j<len - 1; ++j){
      if(arr[j+1] < arr[j]){
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void TrabPradKnutAlg(){
  const int SIZE = 11;
  char tbkArr[SIZE] = {0};
  char tempArr[SIZE] = {0};
  printf("Enter 11 numbers: \n");

  for(int i=0; i<SIZE; ++i){
    int t;
    scanf("%i", &t);
    tbkArr[i] = (char)t;
  }

  //reverse
  for(int i=SIZE-1, j=0; j<SIZE; --i, ++j){
    *(tempArr+j) = *(tbkArr+i);
  }

  for(int i=0; i<SIZE; i++){
    double result = sqrt(abs(tempArr[i])) + 5 * pow(tempArr[i], 3);
    printf("%4f\n", result);
    if(result > 400)
      printf("Value %d. Computed value is greater then 400", (int)*(tempArr+i));
  }

}

void bubbleSort2D(char** arr, const int row, const int col){
  for(int i=0; i<row; ++i){
    bubbleSort(arr[i], col);
  }
}

int main(int argc, char *argv[]) {

  const int row = 5;
  const int col = 5;
  int border = 100;

  char** arr = initArray(arr, row, col);
  fill2dIntArray(arr, row, col, border);
  print2dIntArray(arr, row, col);

  //1
  bubbleSort2D(arr, row, col);
  printf("\n");
  print2dIntArray(arr, row, col);
  printf("\n");

  //2
  TrabPradKnutAlg();


  return 0;
}
