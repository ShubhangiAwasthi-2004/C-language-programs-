#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, int bt) {
    Process* newNode = (Process*)malloc(sizeof(Process));
    newNode->pid = pid;
    newNode->burst_time = bt;
    newNode->remaining_time = bt;
    newNode->waiting_time = 0;
    newNode->turnaround_time = 0;
    newNode->next = NULL;
    return newNode;
}

void appendProcess(Process** head, Process* p) {
    if (*head == NULL) {
        *head = p;
        p->next = *head;
        return;
    }

    Process* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    
    temp->next = p;
    p->next = *head;
}

void roundRobinScheduler(Process* head, int quantum) {
    int time = 0;
    bool done;
    Process* current = head;

    do {
        done = true;
        Process* temp = current;
        do {
            if (temp->remaining_time > 0) {
                done = false;
                if (temp->remaining_time > quantum) {
                    time += quantum;
                    temp->remaining_time -= quantum;
                } else {
                    time += temp->remaining_time;
                    temp->waiting_time = time - temp->burst_time;
                    temp->turnaround_time = time;
                    temp->remaining_time = 0;
                }
            }
            temp = temp->next;
        } while (temp != current);
    } while (!done);
}

void display(Process* head, int n) {
    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    Process* temp = head;
    float total_wt = 0, total_tat = 0;
    int count = 0;
    do {
        printf("P%d\t%d\t%d\t%d\n", temp->pid, temp->burst_time, temp->waiting_time, temp->turnaround_time);
        total_wt += temp->waiting_time;
        total_tat += temp->turnaround_time;
        temp = temp->next;
        count++;
    } while (temp != head && count < n);

    printf("\nAvg Waiting Time: %.2f", total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, quantum, bt;
    Process* head = NULL;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &bt);
        appendProcess(&head, createProcess(i + 1, bt));
    }

    roundRobinScheduler(head, quantum);
    display(head, n);

    return 0;
}
