#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Stack pointers
struct Node *top = NULL;

// Queue pointers
struct Node *front = NULL;
struct Node *rear = NULL;


// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/////////////////////////////////////////////////////////////
//                    STACK OPERATIONS                    //
/////////////////////////////////////////////////////////////

// PUSH
void push(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// POP
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped from the stack\n", temp->data);
    top = top->next;
    free(temp);
}

// DISPLAY STACK
void displayStack() {
    struct Node *temp = top;
    if (temp== NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack (top to bottom) elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////
//                    QUEUE OPERATIONS                    //
/////////////////////////////////////////////////////////////

// ENQUEUE
void enqueue(int value) {
    struct Node *newNode = createNode(value);

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to the queue\n", value);
}

// DEQUEUE
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("%d dequeued from queue\n", temp->data);

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}

// DISPLAY QUEUE
void displayQueue() {
    struct Node *temp = front;
    if (temp == NULL) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue (front to rear) elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////

int main() {
    int choice, value, ch;

    while (1) {
        printf("\n--- Singly Linked List Simulation ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // ---------------- STACK MENU ----------------
            case 1:
                while (1) {
                    printf("\n--- Stack Menu ---\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display Stack\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &ch);

                    switch (ch) {
                        case 1:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            push(value);
                            break;

                        case 2:
                            pop();
                            break;

                        case 3:
                            displayStack();
                            break;

                        case 4:
                            goto main_menu;
                        default:
                            printf("Invalid Choice!\n");
                    }
                }
                break;

            // ---------------- QUEUE MENU ----------------
            case 2:
                while (1) {
                    printf("\n--- Queue Menu ---\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display Queue\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &ch);

                    switch (ch) {
                        case 1:
                            printf("Enter value to enqueue: ");
                            scanf("%d", &value);
                            enqueue(value);
                            break;

                        case 2:
                            dequeue();
                            break;

                        case 3:
                            displayQueue();
                            break;

                        case 4:
                            goto main_menu;
                        default:
                            printf("Invalid Choice!\n");
                    }
                }
                break;

            // ---------------- EXIT ----------------
            case 3:
                printf("Exiting....\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    main_menu: ;
    }
    return 0;
}
