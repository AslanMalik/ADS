#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

class Deque{
    public:

    int sz;
    Node *front, *rear;

    Deque() {
        sz = 0;
        front = rear = NULL;
    }
    
    void push_back(int data) {
        Node *newNode = new Node(data);
        sz++;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }


    void push_front(int data) {
        Node *newNode = new Node(data);
        sz++;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pop_front() {
        if (front == NULL)
        {
            return;
        }

        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }
        
        delete temp;
        sz--;
    }

    void pop_back() {
        if (rear == NULL)
        {
            return;
        }

        if (front == rear) {                          // один элемент
            delete rear;
            front = rear = nullptr;
            --sz;
            return;
        }
        
        Node* last = rear;

        rear = rear->prev;
        rear->next = NULL;
        delete last;
        sz--;
    }

    void front_print() {
        if (front == NULL)
        {
            return;
        }
        cout << front->data << " ";
    }

    void back_print() {
        if (rear == NULL)
        {
            return;
        }
        cout << rear->data << " ";
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

};

int main() {
    return 0;
}