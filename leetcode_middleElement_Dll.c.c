#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertBegin (struct Node** head, int val) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

int findmiddle (struct Node** head) {
    if (head == NULL) {
        printf("List is empty");
    }

    int count=0;
    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if (count%2 == 0) {
        return (count/2 +1);
    }

    else {
        return ((count+1)/2);
    }
}


void displayList(struct Node* node) {
    struct Node* last;
    while (node != NULL) {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if (node == NULL) {
        printf("NULL\n");
    }
}



int main() {
    struct Node* head = NULL;

    insertBegin(&head, 1);
    insertBegin(&head, 2);
    insertBegin(&head, 3);
    insertBegin(&head, 4);
    insertBegin(&head, 5);

    printf("Initial List : ");
    displayList(head);

    int val1 = findmiddle(head);
    printf("Middle element is : %d\n", val1);

    int val2 = findmiddle(head);
    printf("Middle element is : %d", val2);

    return 0;
}