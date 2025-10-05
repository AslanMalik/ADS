#include <iostream>
using namespace std;


class Node {
    public:

    string data;
    Node *next;

    Node(string data) {
        this->data = data;
        this->next = NULL;
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



    void push(string data) {
        Node *new_node = new Node(data);
        if (sz == 0)
        {
            front = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        sz++;
        
    }


    void rotate() {
        Node *new_node = front;
        front = front->next;
        tail->next = new_node;
        tail = new_node;
    }

    void pop() {
        front = front->next;
        sz--;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

};





int main() {

    int n, k;
    cin >> n >> k;

    LinkedList ls;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        ls.push(s);
    }



    for (int i = 0; i < k; i++)
    {
        ls.rotate();
    }
    

    for (int i = 0; i < n; i++)
    {
        cout << ls.front->data << " ";
        ls.front = ls.front->next;
    }
    
    
    





    return 0;
}