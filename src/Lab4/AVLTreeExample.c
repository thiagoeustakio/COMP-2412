#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int d){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    temp->height = 0;

    return temp;
}

int height(struct Node* node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}

int max(int va, int vb){
    return (va>vb) ? va : vb;
}

void updateheight(struct Node* node){
    if(node == NULL){
        return;
    }
    node->height = max(height(node->left), height(node->right)) + 1; 
}

int balancefactor(struct Node* node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct Node* rotateleft(struct Node* node){
    if (node == NULL || node->right == NULL){
        return node;
    }
    struct Node* nroot = node->right;
    node->right = nroot->left;
    nroot->left = node;

    return nroot;
}

struct Node* insertNode(struct Node* root, int data){
    if (root==NULL){
        root = createNode(data);
        return root;
    }
    if ( data > root->data){
        root->right = insertNode(root->right, data);
        // return root; // return rotateleft(root);
    }
    if (data < root->data){
        root->left = insertNode(root->left, data);
        // return root;
    }
    if ( data == root->data){
        return root;
    }

    updateheight(root);
    int bf = balancefactor(root); // will go from 2 to -2

    if(bf < -1){
        //rotate left
        printf("RotatinLeft on %d", root->data);
        return rotateleft(root);
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
    root = insertNode(root, 1);

    printf("InOrder Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

}
