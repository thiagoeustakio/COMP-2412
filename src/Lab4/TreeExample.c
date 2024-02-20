#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int d){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}

struct Node* insertNode(struct Node* root, int data){
    if (root==NULL){
        root = createNode(data);
        return root;
    }
    if ( data > root->data){
        root->right = insertNode(root->right, data);
        return root;
    }
    if (data < root->data){
        root->left = insertNode(root->left, data);
        return root;
    }
    if ( data == root->data){
        return root;
    }
}

void inOrderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf(" %d", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d", root->data);
}

int main(){
    struct Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 11);
    insertNode(root, 9);
    insertNode(root, 12);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 1);

    // printf("The data in the root is %d\n", root->data);
    // printf("The data in the root->right is %d\n", root->right->data);
    // printf("The data in the root->right->right is %d\n", root->right->right->data);
    // printf("The data in the root->left is %d\n", root->left->data);

    printf("InOrder Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

}
