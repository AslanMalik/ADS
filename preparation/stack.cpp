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


class Stack{
    public:

    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }


    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        sz++;
    }


    void pop() {
        if (top == NULL)
        {
            return;
        }
        
        cout << top->data << " ";
        Node * temp = top;
        top = top->next;
        delete temp;
        sz--;
    }

    void peek() {
        cout << top->data << " ";
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