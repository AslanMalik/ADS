#include <iostream>
#include <queue>
using namespace std;


class Node {
    public:
    Node *next;
    int data;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};



class Queue {
    public:
    Node *front, *tail;
    int sz;

    Queue() {
        front = NULL;
        tail = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *new_node = new Node(data);
        if(sz == 0) {
            front = tail = new_node;            
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        
        sz++;        
    }

    void pop() {
        front = front->next;
        sz--;
    }


    int size(){
        return sz;
    }

    bool empty(){ 
        return sz == 0;
    }

};


int main() {
    Queue qu;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        qu.push(t);
    }


    int count = 0;

    while (qu.front != NULL)
    {   
        if (count == 0)
        {
            cout << qu.front->data << " ";
            count++;
        }
        else
        {
            count--;
        }
        
        qu.front = qu.front->next;
    }
    
    

    
    return 0;
}
