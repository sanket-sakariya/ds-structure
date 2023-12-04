#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

void deleteNodeBeforePosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
    } else {
        struct Node* temp = *head;
        int currentPosition = 1;

        while (temp->next != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (currentPosition == position - 1 && temp->prev != NULL) {
            struct Node* nodeToDelete = temp->prev;
            temp->prev = nodeToDelete->prev;
            if (nodeToDelete->prev != NULL) {
                nodeToDelete->prev->next = temp;
            } else {
                *head = temp;
            }
            free(nodeToDelete);
        } else {
            printf("Invalid position or position too close to the beginning\n");
        }
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);

    printf("Original list: ");
    displayList(head);

    insertAtEnd(&head, 4);

    printf("List after inserting at the end: ");
    displayList(head);

    deleteLastNode(&head);

    printf("List after deleting the last node: ");
    displayList(head);

    deleteNodeBeforePosition(&head, 2);

    printf("List after deleting a node before position 2: ");
    displayList(head);

    freeList(head);

    return 0;
}