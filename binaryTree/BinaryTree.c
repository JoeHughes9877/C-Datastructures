#include <stdio.h>
#include <stdlib.h>

// Define the Node structure and alias 'Node' using typedef
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
Node *findMax(Node *root);  // Maximum value in BST
int isBalanced(Node *root); // Check if tree is balanced

// Sample main function
int main() {
  printf("Binary Tree Test\n");
  return 0;
}
