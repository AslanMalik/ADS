#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next= NULL;
    }
};



class Stack {
    public:

    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    
    void push(int data) {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        sz++;
    }


    void pop() {
        if (top != NULL)
        {
            top = top->next;
            sz--;
        }
    }

    int size() {
        return this->sz;
    }

    bool empty() {
        return sz == 0;
    } 

};




int main() {

    Stack st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        st.push(t);
    }
    

    while (!st.empty())
    {
        cout << st.top->data<< " ";
        st.top = st.top->next;
    }
    






    return 0;
}