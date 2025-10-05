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



class Stack {
    public:
    int sz;
    Node *top;

    Stack() {
        sz = 0;
        top = NULL;
    }


    void push(string data) {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        sz++;
    }

    void pop(){
        top = top->next;
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


    int n;
    cin >> n;
    Stack st;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (st.empty() == true)
        {
            st.push(s);
        }
        else
        {
            if (s != st.top->data)
            {
                st.push(s);
            }
        }
        
    }



    cout << "All in all: " << st.size() << endl << "Students:" << endl;

    while (!st.empty())
    {
        cout << st.top->data << endl;
        st.pop();
    }
    
    

    return 0;
}