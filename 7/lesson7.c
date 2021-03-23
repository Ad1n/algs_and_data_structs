#include "lesson.h"

#define MEDIAN(A, B, C) (((A) > (B)) ? (((A) > (C)) ? (A) : (B)) : (((B) > (C)) ? (B) : (C)))

// Hor quick sort
void qs(int* arr, int first, int last){
  int i = first;
  int j = last;

  int x = arr[(first + last) / 2];

  do {
    while(arr[i] < x) i++;
    while(arr[j] > x) j--;

    if (i <= j){
      swapInt(&arr[i], &arr[j]);
      i++;
      j--;
    }
  } while(i <= j);

  if(i < last) qs(arr, i, last);
  if(first < j) qs(arr, first, j);
}

// Sort by inserts
void sortInserts(int* arr, int len){
  int temp;
  int pos;
  for(int i=1; i < len; ++i){
    temp = arr[i];
    pos = i - 1;

    while (pos >= 0 && arr[pos] > temp) {
      arr[pos + 1] = arr[pos];
      pos--;
    }

    arr[pos + 1] = temp;
  }
}

int* computeMedian(int* arr, int first, int last, int center){
  return (arr[first] > arr[last]) ? ((arr[first] > arr[center]) ? &arr[first] : &arr[center] ) : ((arr[last] > arr[center]) ? &arr[last] : &arr[center]);
}

// Improved quicksort algorithm
void qs2_0(int* arr, int first, int last){
  int median;
  int center;

  if(last + 1 <= 10){
    center = (first + last) / 2;
    median = *computeMedian(arr, first, last, center);
    swapInt(&median, &arr[(first + last) / 2]);
    qs(arr, first, last);
  } else {
    sortInserts(arr, last + 1);
  }
}

int main(int argc, char *argv[]) {
  const int SZ = 30;
  int arr[SZ];
  fillIntRandom(arr, SZ, 100);
  printIntArray(arr, SZ);

  qs2_0(arr, 0, SZ - 1);
  printIntArray(arr, SZ);

  return 0;
}
