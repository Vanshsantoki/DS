#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode (int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* insert (struct node* Node, int val) {
    if (Node == NULL) {
        return newnode(val);
    }

    else if(Node->data < val) {
        Node->right = insert(Node->right, val);
    }

    else if (Node->data > val) {
        Node->left = insert(Node->left, val);
    }

    return Node;
}

void preorder (struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder (struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder (struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    int key;
    int ans;
    struct node* root = NULL;
    root = insert(root, 60);
    insert(root, 20);
    insert(root, 80);
    insert(root, 40);
    insert(root, 70);
    insert(root, 50);

    printf("Preorder Traverdal : ");
    preorder(root);
    printf("\n");

    printf("inorder Traverdal : ");
    inorder(root);
    printf("\n");

    printf("postorder Traverdal : ");
    postorder(root);
    printf("\n");

    printf("Enter element to search : ");
    scanf("%d", &key);


