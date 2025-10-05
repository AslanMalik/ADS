#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
}


class Linked{
    public:
    int sz;
    Node* head, *tail;

    Linked() {
        sz = 0;
        head = tail = NULL;
    }


    void push(int data) {
        Node* new_node = new Node(data);
        if (sz == 0)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        
        sz++;
        
    }


    void print() {
        Node* cur = head;

        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur=cur->next;
        }
        
    }
}



int main() {
    return 0;
}