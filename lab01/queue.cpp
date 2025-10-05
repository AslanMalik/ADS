#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = next;
    }
}


class Queue{
    public:

    Node* head, *tail;
    int sz;

    Queue(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }


    void push(int data) {
        Node* new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        sz++;
    }


}

int main() {
    return 0;
}