#include "../data/geek.c"
#include "../data/9-2-depth.c"
#include "../data/Stack.c"
#include "../data/Stack.h"

Stack tStack;

//1 Depth travers using stack
void depthTraversStack() {
  int cur;
  int r;
  int st = 0;
  visitedDepth[st] = 1;
  pushStack(&tStack, 0);

  while(tStack.cursor != -1) {
    cur = popStack(&tStack);
    printf("%d ", cur);

    for(r = 0; r < n; ++r) {
      if(matrix[cur][r] == 1 && !visitedDepth[r]) {
        visitedDepth[r] = 1;
        pushStack(&tStack, r);
      }
    }
  }
}
//---------------------------


int main(int argc, char *argv[]) {
  tStack.cursor = -1;
  depthTraversStack();

  return 0;
}
