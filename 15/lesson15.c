#include "../data/geek.h"

// 15.1 Hash function
int simpleHashSum(char* in) {
  int sum = 0;
  for(int i = 0; in[i] != '\0'; ++i) {
    sum += (int)in[i];
  }
  return sum;
}
// ------------------

// 15.2 Greedy alg
const int size = 5;

int* exchange(int* money, int size, int sum){
  int max = 0;
  // Pseudo-stack
  int* res = (int*) calloc(sum, sizeof(int));
  int cursor = 0;
  //----
  int tempSum = sum;
  int idxMax = 0;

  while(tempSum != 0) {
    for(int i = 0; i < size; ++i) {
      if (money[i] > max) {
        max = money[i];
        idxMax = i;
      }
    }

    if (money[idxMax] == 0)
      break;

    money[idxMax] = 0;

    while (tempSum - max >= 0) {
      printf("get %d c \n", max);
      tempSum -= max;
      res[cursor] = max;
      cursor++;
    }

    max = 0;
  }
  return res;
}
// ----------------

int main(int argc, char *argv[]) {
  // 15.1
  char* str = "Welcome to test string";
  printf("%d\n", simpleHashSum(str));
  // -----

  // 15.2 Имеются монеты номиналом 50, 10, 5, 2, 1 коп.
  // Напишите функцию которая минимальным количеством монет наберет сумму 98 коп.
  // Для решения задачи используйте “жадный” алгоритм.
  int money[size] = {50, 10, 5, 2, 1};
  int* res = exchange(money, size, 98); // 98 is maximum of array

  for (int i = 0; i < 98; ++i) {
    if (res[i] != 0)
      printf("from arr -> %d", res[i]);
  }

  free(res);
  //--------------------------------------------------------------------------------
  return 0;
}
