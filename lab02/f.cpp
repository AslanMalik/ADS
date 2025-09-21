#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->next = NULL;
        this->data = data;
    }
};



class LinkedList{
    public:
    int sz;
    Node *front, *tail;

    LinkedList() {
        sz = 0;
        front = NULL;
        tail = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (sz == 0)
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

    void pop(){
        front = front->next;
        sz--;
    }

    int size(){
        return sz;
    }

    bool empty(){
        return sz==0;
    }



    void replace(int value, int index) {
        Node *newNode = new Node(value);
        Node* cur = front;
        int find = 0;



        if (index == 0) 
        {
            newNode->next = front;
            front = newNode;
            return;

        }
        

        while (find + 1 != index)
        {
            cur = cur->next;
            find++;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        
    }

};





int main() {


    LinkedList ll;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ll.insert(t);
    }


    int value, index;
    cin >> value >> index;

    ll.replace(value, index);

    while (ll.front != NULL)
    {
        cout << ll.front->data << " ";
        ll.front = ll.front->next;
    }
    
    


    return 0;
}