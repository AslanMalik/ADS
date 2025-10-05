#include <iostream>
using namespace std;


class Node{
    public:

    int data;
    Node* next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LinkedList{
    public:
    int sz;
    Node *head, *tail;

    LinkedList() {
        sz = 0;
        head = tail = NULL;
    }

    Node* reverse() {
        Node* prev = NULL;
        Node* next = NULL;
        Node* cur = head;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
        
    }



    void delete_head(Node *cur) {
        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        
        Node *temp = head;

        head = head->next;

        tail->next = head;
        head->prev = tail;
        delete temp;
    }

    void insert_edn(int data) {
        Node* new_node = new Node(data);

        if (tail == NULL)
        {
            head = tail = new_node;
            return;
        }
        

        if (head == tail)
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            return;
        }


        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;        

    }

};



int main() {
    return 0;
}