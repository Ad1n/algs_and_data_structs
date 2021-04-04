#include "../data/geek.c"

typedef int boolean;


// 12.1 Check bin tree balance
int maxLvl(int a, int b) {
  return (a >= b) ? a : b;
}

int treeHeight(BinTreeIntNode *node) {
  if (node == NULL) {
    return 0;
  }

  return 1 + maxLvl(treeHeight(node->left), treeHeight(node->right));
}

boolean isBalanced(BinTreeIntNode *root){
  if (root == NULL) {
    return true;
  }

  int lHeight = treeHeight(root->left);
  int rHeight = treeHeight(root->right);

  if (abs(lHeight - rHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
    return true;
  }

  return false;
}

// ------------------------------------

// 12.2 50th bin trees

int randomize() {
  int r;

  switch (rand() % 2) {
  case 0:
    r = abs(rand() % 1000 - rand() % 100);
    break;
  case 1:
    r = rand() % 100000 + rand() % 10000;
    break;
  case 3:
    r = rand() % 123 * rand() % 10;
    break;
      }
  return r;
}

BinTreeIntNode* generateBinTree(int count) {
  BinTreeIntNode *root = treeInsert(root, randomize());

  for (int i = 0; i < count - 1; ++i) {
    treeInsert(root, randomize() + i + 1);
  }

  return root;
}
// ------------------------------------

// 12.3 Recursive search in bin tree
BinTreeIntNode* searchNode(BinTreeIntNode *root, int data) {
  if (root) {
    if(root->key == data) {
      printf("FOUND!\n");
      return root;
    } else {
      BinTreeIntNode *tmp = searchNode(root->left, data);
      if (tmp) return tmp;

      tmp = searchNode(root->right, data);
      if (tmp) return tmp;
    }
  }

  return NULL;
}
// ---------------------------------

int main(int argc, char *argv[]) {
  srand(time(0));
  BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");

    // 12.1
    printf("IS BALANCED: %d\n", isBalanced(tree));
    //--------------------

    // 12.2a
    const int SIZE = 1;
    const int NODES_COUNT = 10;
    BinTreeIntNode** rootArr = (BinTreeIntNode**) malloc(sizeof(BinTreeIntNode*) * SIZE);

    for (int i = 0; i < SIZE; ++i) {
      rootArr[i] = generateBinTree(NODES_COUNT);
    }
    // -------------------

    // 12.2b
    int balancedCount = 0;

    for (int i = 0; i < SIZE; ++i) {
      if (isBalanced(rootArr[i]) == true)
        balancedCount++;
    }

    printf("Percent of balanced trees: %d percent(s)\n\n", (balancedCount / SIZE) * 100);

    for (int i = 0; i < SIZE; ++i) {
      free(rootArr[i]);
    }

    free(rootArr);
    // -------------------

    // 12.3
    printBinTree(tree);
    int t_value = 16;
    BinTreeIntNode *target = searchNode(tree, t_value);
    if (target != NULL)
      printf("Found NODE key:[%d]\n", target->key);
    else
      printf("Tree has no nodes with value: %d\n", t_value);
    // -------------------
  return 0;
}
