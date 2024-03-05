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

    updateheight(node);
    updateheight(nroot); 

    return nroot;
}

struct Node* rotateright(struct Node* node){
    if (node == NULL || node->left == NULL){
        return node;
    }

    struct Node* nroot = node->left;
    node->left = nroot->right;
    nroot->right = node;

    updateheight(node);
    updateheight(nroot); 

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
    // printf("BF of %d, -> %d\n", root->data, bf);

    if(bf < -1){
        if(data < root->right->data){
            printf("inserting on on the left of the right child\n");
            root->right = rotateright(root->right);
        }

        //rotate left
        printf("Inserting %d RotatinLeft on %d\n",data, root->data);
        return rotateleft(root);
    }
    return root;
}

void inOrderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    // printf(" (data %d, height %d)", root->data, root->height);
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
    root = insertNode(root, 3);
    root = insertNode(root, 2);
    // root = insertNode(root, 4);
    // root = insertNode(root, 5);
    // root = insertNode(root, 7);
 
    printf("InOrder Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

}
