#include <iostream>
#include <map>
using namespace std;


class Node{
    public:

    char data;
    Node *next;

    Node(char data){
        this->data = data;
        this->next = NULL;
    }
};

class Linked{
    public:
    Node *head, *tail;
    int sz;

    Linked() {
        sz =0;
        head = tail = NULL;
    }

    void append(char data) {
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

    void check(){

    }

};



int main() {



    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        Linked ls;
        map<char,int> count;

        for (int j = 0; j < k; j++)
        {
            char c;
            cin >> c;

            ls.append(c);
            count[c]++;

            Node* cur = ls.head;
            while (cur != NULL && count[cur->data] > 1)
            {
                cur = cur->next;
            }
            if (cur == NULL)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << cur->data << " ";
            }
            
            
            

        }
        cout << endl;
        
    }
    





    return 0;
}