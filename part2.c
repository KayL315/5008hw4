/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}


int isEmpty(struct Node* head) {
    return (head == NULL);
}


void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued: %d (Priority: %d)\n", data, priority);
}


void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued: %d (Priority: %d)\n", temp->data, temp->priority);
    free(temp);
}


void display(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    while (head != NULL) {
        printf("%d (Priority: %d) ", head->data, head->priority);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, priority;

    do {
        printf("Priority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&head, data, priority);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);


    while (!isEmpty(head)) {
        dequeue(&head);
    }

    return 0;
}
