#include <iostream>
using namespace std;


class Node{
    public:

    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:

    Node *front, *tail;
    int sz;  
    
    Queue() {
        sz = 0;
        front = tail = NULL;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if (front == NULL)
        {
            front = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void pop() {
        if (front == NULL)
        {
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
        {
            tail = NULL;
        }
        
        sz--;
        delete temp;
    }


    void front_print() {
        if (front == NULL)
        {
            return;
        }

        cout << front->data << " ";
    }

    bool empty() {
        return sz == 0;
    }

    int size() {
        return sz;
    }
};

int main() {
    return 0;
}