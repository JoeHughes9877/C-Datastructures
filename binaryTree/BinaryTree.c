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
int search(Node *root, int target);     // Search for value
Node *deleteNode(Node *root, int data); // Delete node from BST

void inorder(Node *root);   // In-order traversal
void preorder(Node *root);  // Pre-order traversal
void postorder(Node *root); // Post-order traversal

int height(Node *root);     // Tree height
int size(Node *root);       // Tree size (node count)
Node *findMin(Node *root);  // Minimum value in BST
Node *findMax(Node *root);  // Maximum value i\\n BST
int isBalanced(Node *root); // Check if tree is balanced

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

// Sample main function
int main() {
  Node *root = createNode(1);
  root = insert(root, 50);
}