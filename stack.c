#include<stdio.h>

void push();
void pop();
void peek();

int N = 5;
int stack[5];
int top = -1;

int main() {
    int ch;
    do {
        printf("Enter your choice: 1.push / 2.pop / 3.peek / 4.exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Choice out of range. Please enter 1, 2, 3, or 4.\n");
                break;
        }
    } while(ch != 4);
    return 0;
}

void push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("Overflow: Cannot enter data, stack is full.\n");
    } else {
        top++;
        stack[top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow: Stack is empty.\n");
    } else {
        int item = stack[top];
        top--;
        printf("Popped item: %d\n", item);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top item: %d\n", stack[top]);
    }
}
