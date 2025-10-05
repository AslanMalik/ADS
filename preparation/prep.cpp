#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *next, *prev;

    Node(int data) {
        this->next = NULL;
        this->prev = NULL;
        this->data = data;
    }
};


class Linked{
    public:

    int sz;
    Node *head, *tail;

    Linked() {
        sz = 0; head = tail = NULL;
    }

    void reverse() {

        Node *cur = head;
        Node *temp = NULL;

        while (cur != NULL)
        {
            temp = cur->prev;
            cur->prev= cur->next;
            cur->next = temp;
            cur = cur->prev;
        }

        if (cur != NULL)
        {
            
        }
        

        


        return ;
    }


    void reverse1() {
        Node *cur = head;
        Node *next = NULL;
        Node *temp = NULL;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = temp;
            temp = cur;
            cur = next;
        }
        return temp;
    }
};


int main() {
    return 0;
}