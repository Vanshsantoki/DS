#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue (int val1) {
    struct node *newnode1 = malloc(sizeof(struct node));
    newnode1->data = val1;
    newnode1->next = NULL;

    if(front == NULL && rear == NULL) {
        front = newnode1;
        rear = newnode1;
    }
    else {
        rear->next = newnode1;
        rear = newnode1;
    }
}

void dequeue() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

void display1() {
    struct node *temp = front;
    while(temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *head = NULL;

void push(int val2) {
    struct node *newnode2 = malloc(sizeof(struct node));
    newnode2->data = val2;
    newnode2->next = head;
    head = newnode2;
}

void pop() {
    struct node *temp;
    if(head == NULL) {
        printf("Stack is empty");
    }

    else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display2() {
    struct node *temp = head;
    while(temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {

    printf("Queue operation using linked list: \n");
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display1();

    printf("After Dequeue operation: \n");
    dequeue();
    display1();

    printf("Stack operation using linked list: \n");
    push(10);
    push(20);
    push(30);

    display2();

    printf("After pop operation: \n");
    pop();
    display2();

    return 0;
}