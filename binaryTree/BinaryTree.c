#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Function Prototypes
Node *createNode(int data);             // Constructor
Node *insert(Node *root, int data);     // Insert into BST
Node *search(Node *root, int target);   // Search for value
Node *deleteNode(Node *root, int data); // Delete node from BST

int height(Node *root);     // Tree height
int size(Node *root);       // Tree size (node count)
Node *findMin(Node *root);  // Minimum value in BST
Node *findMax(Node *root);  // Maximum value i\\n BST
int isBalanced(Node *root); // Check if tree is balanced

void inorder(Node *root);   // In-order traversal
void preorder(Node *root);  // Pre-order traversal
void postorder(Node *root); // Post-order traversal

Node *createNode(int data) {
  Node *n = malloc(sizeof(Node));
  if (n == NULL) {
    printf("malloc failed");
    return NULL;
  }
  n->left = NULL;
  n->right = NULL;
  n->data = data;

  return n;
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }

  if (data > root->data) {
    if (root->right == NULL) {
      Node *newNode = createNode(data);
      root->right = newNode;
      return root;
    } else {
      Node *newNode = insert(root->right, data);
      root->right = newNode;
      return root;
    }
  } else if (data < root->data) {
    if (root->left == NULL) {
      Node *newNode = createNode(data);
      root->left = newNode;
      return root;
    } else {
      Node *newNode = insert(root->left, data);
      root->left = newNode;
      return root;
    }
  }
  return root;
}

Node *search(Node *root, int target) {
  if (root == NULL) {
    printf("tree is empty\n");
    return NULL;
  }
  if (target == root->data) {
    return root;
  }

  if (target > root->data) {
    return search(root->right, target);
  }
  if (target < root->data) {
    return search(root->left, target);
  }

  printf("target is not in tree");
  return NULL;
}

Node *deleteNode(Node *root, int data) {
  if (root == NULL) {
    printf("tree is empty\n");
    return NULL;
  }

  if (data > root->data) {
    root->right = deleteNode(root->right, data);
    return root;
  } else if (data < root->data) {
    root->left = deleteNode(root->left, data);
    return root;
  } else if (root->data == data) {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL && root->right != NULL) {
      Node *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->left != NULL && root->right == NULL) {
      Node *tmp = root->left;
      free(root);
      return tmp;
    } else if (root->left != NULL && root->right != NULL) {
      Node *tmp = findMin(root->right);

      if (!tmp) {
        printf("find Min failed, NULL returned.\n");
        return NULL;
      }
      root->data = tmp->data;
      root->right = deleteNode(root->right, tmp->data);
      return root;
    }
  }
  printf("delete failed.\n");
  return NULL;
}

int height(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return 0;
  }

  int left_height = 0;
  int right_height = 0;

  if (root->left != NULL) {
    left_height = height(root->left);
  }
  if (root->right != NULL) {
    right_height = height(root->right);
  }

  if (left_height > right_height) {
    return left_height + 1;
  } else {
    return right_height + 1;
  }
}

int size(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return 0;
  }

  int total_nodes = 1;

  if (root->left != NULL) {
    total_nodes += size(root->left);
  }
  if (root->right != NULL) {
    total_nodes += size(root->right);
  }

  return total_nodes;
}

Node *findMin(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return NULL;
  }

  Node *newNode = root;
  while (root->left != NULL) {
    newNode = root;
    root = root->left;
  }
  return root;
}

Node *findMax(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return NULL;
  }

  Node *newNode = root;
  while (root->right != NULL) {
    newNode = root;
    root = root->right;
  }
  return root;
}

int isBalanced(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return 0;
  }

  int right_hight = 0;
  int left_hight = 0;

  right_hight += height(root->right);
  left_hight += height(root->left);

  if (abs(right_hight - left_hight) > 1) {
    return 0;
  }

  return isBalanced(root->left) && isBalanced(root->right);
}

void inorder(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return;
  }
  inorder(root->left);
  printf("%i\n", root->data);
  inorder(root->right);
}

void preorder(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return;
  }
  printf("%i\n", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL) {
    printf("tree is empty\n");
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%i\n", root->data);
}

int main() {
  Node *root = createNode(50);

  // Insert nodes
  int values[] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < 7; i++) {
    root = insert(root, values[i]);
  }

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  // Search test
  int target = 40;
  Node *found = search(root, target);
  printf("Search %d: %s\n", target, found ? "Found" : "Not Found");

  // Min and Max
  Node *min = findMin(root);
  Node *max = findMax(root);
  printf("Minimum: %d\n", min ? min->data : -1);
  printf("Maximum: %d\n", max ? max->data : -1);

  // Tree size
  printf("Size of tree: %d\n", size(root));

  // Height
  printf("Height of tree: %d\n", height(root));

  // Balance check
  int balanced = isBalanced(root);
  printf("Tree is %s\n", balanced ? "Balanced" : "Not Balanced");

  // Deletion test
  printf("Deleting node 30...\n");
  root = deleteNode(root, 30);
  printf("Inorder after deletion: \n");
  inorder(root);
  printf("\n");

  return 0;
}
