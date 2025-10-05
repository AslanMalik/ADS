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

    void print() {
        Node *cur = front;

        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        
    }


    void pop_end(int n) {
        Node *cur = front;

        for (int i = 0; i < n-1; i++)
        {
            cur = cur->next;
        }

        Node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
           
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

    int k; cin >> k;
    ll.pop_end(k);

    ll.print();

    
    
    


    return 0;
}