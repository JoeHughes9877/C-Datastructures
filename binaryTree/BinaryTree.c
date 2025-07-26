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
  return NULL;
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
  return newNode;
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

  if (root->right == NULL && root->left == NULL) {
    if (left_height > right_height) {
      return left_height + 1;
    } else {
      return right_height + 1;
    }
  }
  printf("height failed");
  return NULL;
}

// Sample main function
int main() {
  Node *root = createNode(1);
  root = insert(root, 50);
}