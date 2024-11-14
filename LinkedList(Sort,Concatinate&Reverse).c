#include<stdio.h>
#include<stdio.h>

typedef struct node {
    int data ;
    struct node *next;
}node;

node *createnode (int val) {
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL) {
        printf("Memory allocation failed!");
        exit(0);
    }
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

node *insertAtBeginning (node *head, int val) {
    node *newnode = createnode(val);
    newnode->next = head;
    return newnode;
}

node *concatenate (node *h1, node *h2) {
    if(h1==NULL) {
        return h2;
    }
    if(h2==NULL) {
        return h1;
    }
    node *temp = h1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = h2;
    return h1;
}

node *sort (node *head) {
    if(head==NULL) {
        return NULL;
    }
    node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if(temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

node *reverse (node *head) {
    node *prev=NULL, *temp, *next;
    temp = head;
    while (temp!= NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void display(node *head1, node *head2)
{
    printf("Linked List 1: ");
    while (head1 != NULL)
    {
        printf("%d -> ", head1->data);
        head1 = head1->next;
    }
    printf("NULL\n");
    printf("Linked List 2: ");
    while (head2 != NULL)
    {
        printf("%d -> ", head2->data);
        head2 = head2->next;
    }
    printf("NULL\n");
}

int main() {
    node *list1 = NULL;
    node *list2 = NULL;
    list1 = insertAtBeginning(list1, 10);
    list1 = insertAtBeginning(list1, 20);

    list2 = insertAtBeginning(list2, 30);
    list2 = insertAtBeginning(list2, 40);

    display(list1, list2);

    printf("After Sorting:\n");
    list1 = sort(list1);
    list2 = sort(list2);
    display(list1, list2);

    printf("After concatenation:\n");
    list1 = concatenate(list1, list2);
    display(list1, list2);

    printf("After reversing:\n");
    list1 = reverse(list1);
    display(list1, list2);

    return 0;

}

