#include <iostream>
#include "queue.h"

using namespace std;

struct QueueNode {
    Item data;
    QueueNode* next;
};

QueueNode *front = NULL, *rear = NULL;

void enqueue(Item item) {
    QueueNode* node = new QueueNode();
    node->data = item;
    node->next = NULL;

    if (!rear) {
        front = rear = node;
        return;
    }
    rear->next = node;
    rear = node;
}

void dequeue() {
    if (!front) {
        cout << "Queue is empty\n";
        return;
    }
    QueueNode* temp = front;
    front = front->next;
    delete temp;
    cout << "Restock processed\n";
}
