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

int search(struct node* root, int val) {
    if (root == NULL ||root->data == val)
        return root;
    else if (root->data > val)
        return search (root->left, val);
    else if (root->data < val)
        return search (root->right, val);
}

int main() {
    int ans;
    int key;
    struct node* root = NULL;
    root = insert(root, 60);
    insert(root, 20);
    insert(root, 80);
    insert(root, 40);
    insert(root, 70);
    insert(root, 50);

    printf("Enter ELement to search: ")
    ans = search(root, key);

    if(ans)
        printf("Element present");
    else
        printf("Element absent");
}
}
