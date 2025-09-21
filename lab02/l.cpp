#include <iostream>
#include <algorithm>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next= NULL;
    }
};

class Linked{
    public:

    int sz;
    Node *head, *tail;

    Linked(){
        sz= 0;
        head =NULL;
        tail=NULL;
    }

    void append(int data){
        Node *new_node = new Node(data);
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

    void print(){
        Node *cur = head;

        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }    
    }

    int Ragnarok() {
        Node *cur = head ->next;

        

        int current_sum = head->data;
        int max_sum = head->data;

        while (cur != NULL)
        {
            current_sum = max(cur->data, cur->data + current_sum);
            max_sum = max(max_sum, current_sum);
            cur = cur->next;
        }
        
        return max_sum;

    }

};







int main() {
    int n;
    cin >> n;
    Linked ls;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ls.append(t);
    }

    cout << ls.Ragnarok();

    
    return 0;
}






