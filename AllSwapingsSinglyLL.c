#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Utility: Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Utility: Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// ************************************
// 1. SWAPPING DATA OF TWO GIVEN NODES
// ************************************
void swapData(struct Node* head, int x, int y) {
    if (x == y) return;

    struct Node *nodeX = NULL, *nodeY = NULL;

    while (head != NULL) {
        if (head->data == x) nodeX = head;
        if (head->data == y) nodeY = head;
        head = head->next;
    }

    if (nodeX && nodeY) {
        int temp = nodeX->data;
        nodeX->data = nodeY->data;
        nodeY->data = temp;
    }
}

// *****************************************
// 2. SWAPPING TWO NODES BY LINKS (NOT DATA)
// *****************************************
void swapNodes(struct Node** head, int x, int y) {
    if (x == y) return;

    struct Node *prevX = NULL, *currX = *head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *prevY = NULL, *currY = *head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) return;

    if (prevX) prevX->next = currY;
    else *head = currY;

    if (prevY) prevY->next = currX;
    else *head = currX;

    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

// *********************************************
// 3. SWAPPING FIRST AND LAST NODE OF LINKED LIST
// *********************************************
void swapFirstAndLast(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    struct Node* first = *head;
    struct Node* prev = NULL;
    struct Node* last = *head;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    if (first == last) return;

    prev->next = first;
    struct Node* temp = first->next;
    first->next = NULL;
    last->next = temp;
    *head = last;
}

// ********************************************************
// 4. SWAPPING KTH NODE FROM START AND KTH FROM END BY LINK
// ********************************************************
int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void swapKthNode(struct Node** head, int k) {
    int n = countNodes(*head);
    if (k > n) return;
    if (2 * k - 1 == n) return;

    struct Node *x_prev = NULL, *x = *head;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y_prev = NULL, *y = *head;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    else *head = y;

    if (y_prev) y_prev->next = x;
    else *head = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}

// *******************************************************
// 5. SWAPPING M-th NODE WITH N-th NODE BY POSITION (BY LINK)
// *******************************************************
void swapByPosition(struct Node** head, int m, int n) {
    if (m == n) return;

    int pos = 1;
    struct Node *prevM = NULL, *currM = *head;
    while (currM && pos < m) {
        prevM = currM;
        currM = currM->next;
        pos++;
    }

    pos = 1;
    struct Node *prevN = NULL, *currN = *head;
    while (currN && pos < n) {
        prevN = currN;
        currN = currN->next;
        pos++;
    }

    if (!currM || !currN) return;

    if (prevM) prevM->next = currN;
    else *head = currN;

    if (prevN) prevN->next = currM;
    else *head = currM;

    struct Node* temp = currM->next;
    currM->next = currN->next;
    currN->next = temp;
}

// ***********************
// MAIN FUNCTION TO DEMO
// ***********************
int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);

    printf("Original List:\n");
    printList(head);

    // 1. Swap data
    printf("\n[1] Swapping data of 20 and 40:\n");
    swapData(head, 20, 40);
    printList(head);

    // 2. Swap nodes by links (by value)
    printf("\n[2] Swapping nodes 30 and 50 by links:\n");
    swapNodes(&head, 30, 50);
    printList(head);

    // 3. Swap first and last node
    printf("\n[3] Swapping first and last node:\n");
    swapFirstAndLast(&head);
    printList(head);

    // 4. Swap kth from start and end
    int k = 2;
    printf("\n[4] Swapping %d-th node from start and end:\n", k);
    swapKthNode(&head, k);
    printList(head);

    // 5. Swap m-th and n-th nodes by position
    int m = 2, n = 4;
    printf("\n[5] Swapping %d-th and %d-th node by position:\n", m, n);
    swapByPosition(&head, m, n);
    printList(head);

    return 0;
}
