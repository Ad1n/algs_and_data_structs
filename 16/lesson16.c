#include "../data/geek.h"

// 1 Caesar
char* caesar(char* in, int key, bool encrypt) {
  int ptr;
  int len = 0;

  for (int i = 0; in[i] != '\0'; ++i) {
    len += 1;
  }

  char* temp = (char*) calloc(len, sizeof(char));

  for (int i = 0; in[i] != '\0'; ++i) {
    if (encrypt == true) {
      ptr = ((int)in[i]) + key;
      temp[i] = (char)ptr;
    } else {
      ptr = ((int)in[i]) - key;
      temp[i] = (char)ptr;
    }
  }

  return temp;
}
// ------------------------------------

// 2 Shuffle
char* shuffle(char* in, int key, bool encrypt) {
  int len = 0;
  int k = 0;
  char** matrix = (char**) calloc(key, sizeof(char*));

  for (int i = 0; in[i] != '\0'; ++i) {
    len += 1;
  }

  char* temp = (char*) calloc(len, sizeof(char));

  for (int i = 0; i < key; ++i) {
    matrix[i] = (char*) calloc(key, sizeof(char));
  }

  for (int i = 0; i < key; ++i) {
    for (int j = 0; j < key; ++j) {
      if (in[k] == '\0') {
        matrix[i][j] = 0;
      }

      matrix[i][j] = in[k];
      k++;
    }
  }

  char* shuffleTemp = (char*) calloc(key, sizeof(char));

  if (encrypt) { // Так как переставляем средние строки то encrypt не важен = )
    shuffleTemp = matrix[1];
    matrix[1] = matrix[2];
    matrix[2] = shuffleTemp;
  } else {
    shuffleTemp = matrix[1];
    matrix[1] = matrix[2];
    matrix[2] = shuffleTemp;
  }

  k = 0;

  for (int i = 0; i < key; ++i) {
    for (int j = 0; j < key; ++j) {
      temp[k] = matrix[i][j];
      k++;
    }
  }


  for (int f = 0; f < key; f++) {
    free(matrix[f]);
  }
  free(matrix);

  return temp;
}
// ------------------------------------

int main(int argc, char *argv[]) {
  // 1
  printf("CAESAR: \n");
  char* in = "hello worldz";
  printf("%s\n", caesar(in, 3, true));
  char* out = "khoor#zruog}";
  printf("%s\n", caesar(out, 3, false));
  // -----------------------------------

  // 2
  printf("SHUFFLE: \n");
  char* outShuffle = "hellrldzo wo";
  printf("%s\n", shuffle(in, 4, true));
  printf("%s\n", shuffle(outShuffle, 4, false));
  // -----------------------------------
  return 0;
}
