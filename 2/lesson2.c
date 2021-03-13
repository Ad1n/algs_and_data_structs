#include <stdio.h>

int isPrime(int a){
  for(int i=2; i<a; i++){
    if(a % i == 0) return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int a;
  printf("Enter natural number >= 1: ");
  scanf("%i", &a);
  printf("Is prime? : %i", isPrime(a));
  return 0;
}
