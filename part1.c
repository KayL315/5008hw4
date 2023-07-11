/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    double data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(double value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, double value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

double findClosestValue(struct Node* root, double target) {
    double closestValue = root->data;
    struct Node* curr = root;

    while (curr != NULL) {
        if (abs(curr->data - target) < abs(closestValue - target)) {
            closestValue = curr->data;
        }

        if (curr->data == target) {
            break;
        } else if (target < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return closestValue;
}

void freeMemory(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int n;
    double target;

    printf("Enter the number of elements in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements of the BST:\n");
    for (int i = 0; i < n; i++) {
        double value;
        scanf("%lf", &value);
        root = insertNode(root, value);
    }

    printf("Enter the target value: ");
    scanf("%lf", &target);

    double closestValue = findClosestValue(root, target);
    printf("Closest number = %.6lf\n", closestValue);

    // Deallocate memory
    freeMemory(root);

    return 0;
}

