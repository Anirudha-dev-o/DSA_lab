#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0; // First element insertion
        queue[++rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        printf("%d deleted from queue.\n", queue[front++]);
    }
}

// Function to display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
