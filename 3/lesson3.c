#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1
void to_binary(int num){
  printf("%i", num % 2);

  if(num/2 <= 1){
    printf("%i", num / 2);
    printf("\n");
    return;
  }
  else {
    to_binary(num/2);
  }
}

//2
void my_pow(int a, int b, int acc){
  acc *= a;

  if(b == 1){
    printf("Result: %i\n", acc);
  }
  else if(b == 0) {
    printf("Result: %i\n", 1);
  }
  else {
    my_pow(a, b-1, acc);
  }
}

//3
void my_pow_2_0(int a, int b, int acc){
  if(b == 0){
    printf("Result 2.0: %i\n", acc);
    return;
  }

  if(b == 1){
    acc *= a;
    printf("Result 2.0: %i\n", acc);
    return;
  }

  if(b % 2 == 0){
    my_pow_2_0(a*a, b/2, acc);
  }
  else {
    acc *= a;
    my_pow_2_0(a, b-1, acc);
  }
}

//4
int routes(int x, int y, int *field[]){
  if(x == 0 && y == 0)
    return 0;
  else if(x == 0 || y == 0)
    return 1;
  else
    if((field[x][y-1] == 0) && (field[x-1][y] == 0)){
      return routes(x, y - 1, field) + routes(x - 1, y, field);
    }
    else if((field[x][y-1] == 1) && (field[x-1][y] == 0)) {
      return routes(x - 1, y, field);
    }
    else if((field[x][y-1] == 0) && (field[x-1][y] == 1)){
      return routes(x, y - 1, field);
    }
    else {
      return 0;
    }
}

int routes2(int x, int y, int *field[]){
  if(x == 0 && y == 0)
    return 0;
  else if(x == 0 || y == 0)
    if(field[x][y] == 1)
      return 0;
    else
      return 1;
  else
     if((field[x][y-1] == 0) && (field[x-1][y] == 0)){
      return routes2(x, y - 1, field) + routes2(x - 1, y, field);
    }
    else if((field[x][y-1] == 1) && (field[x-1][y] == 0)) {
      return routes2(x - 1, y, field);
    }
    else if((field[x][y-1] == 0) && (field[x-1][y] == 1)){
      return routes2(x, y - 1, field);
    }
    else {
      return 0;
    }
    /* return routes2(x-1, y, field) + routes2(x, y-1, field); */
}


int main(int argc, char *argv[]) {
  //1
  int dec_num;
  printf("Enter decimal number: ");
  scanf("%i", &dec_num);
  to_binary(dec_num);

  //2
  int a;
  int b;
  printf("Enter a number: ");
  scanf("%i", &a);
  printf("Enter b number: ");
  scanf("%i", &b);
  my_pow(a, b, 1);

  //3
  my_pow_2_0(a, b, 1);


  //4
  srand(time(0));
  const int sizeX = 5;
  const int sizeY = 5;
  int field[sizeX][sizeY];
  int *ptr_field[sizeY] = { field[0], field[1], field[2], field[3], field[4] };

  //Генерируем поле
  for(int y=0; y < sizeY; ++y){
    for(int x=0; x < sizeX; ++x) {
      if(x == (sizeX - 1) && y == (sizeY - 1)){
        //целевая клетка всегда доступна к ходу
        field[x][y] = 0;
        continue;
      }
      if(x == 0 && y ==0){
        //Начальное точка на поле всегда 0
        field[x][y] = 0;
        continue;
      }
      field[x][y] = rand() % 2;
    }
  }

  //Показываем поле
  printf("Field__________\n");
  for(int y=0; y < sizeY; ++y){
    for(int x=0; x < sizeX; ++x) {
      printf("%i ",field[x][y]);
    }
    printf("\n");
  }

  //Выводим кол-во маршрутов
  for(int y=0; y < sizeY; ++y){
   for(int x=0; x < sizeX; ++x) {
     printf("%5d ", routes2(x, y, ptr_field));
    }
   printf("\n");
  }

  return 0;
}
