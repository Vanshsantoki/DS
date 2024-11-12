#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int item, front = 0, rear = -1, q[10];

void Inqueu() {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    rear = rear + 1;
    q[rear] = item;
}

int Dequeu() {
    if (front > rear) 
        return -1;
    return q[front++];
}

void displayQ() {
    int i;
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of queue:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", q[i]);
    }
}

int main() {
    int choice;

    while(true) {
        printf("\n1: Insert rear\n2: Delete front\n3: Display\n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                Inqueu();
                break;
            case 2:
                item = Dequeu();
                if (item == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Item deleted = %d\n", item);
                }
                break;
            case 3:
                displayQ();
                break;
            default:
                exit(0); 
        }
    }
}