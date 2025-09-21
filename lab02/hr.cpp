#include <iostream>
 
using namespace std;
 
class Node{
    public:
    int data;
    Node *next;
    // Node *prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        // this->prev = NULL;
    }
};


class Linked {
    public:
    int sz;
    Node *head, *tail;


    Linked() {
        sz = 0;
        head = tail = NULL;
    }


    void insert(int value ,int index) {
        Node* new_node = new Node(value);
        if (sz == 0)
        {
            head = tail = new_node;
            sz++;
            return;
        }
        else
        {
            if (index == 0)
            {
                new_node->next = head;
                head = new_node;
                sz++;
                return;
            }

            if (index == sz)
            {
                tail->next = new_node;
                tail = new_node;
                sz++;
                return;
            }

            
            int index_tipo = 0;

            Node *cur = head;

            while (index_tipo < index-1)
            {
                index_tipo++;
                cur = cur->next;
            }

            new_node->next= cur->next;
            cur->next = new_node;
            sz++;
            return;
            
        }
        
    }


    void remove(int index) {
        
        if (index == 0)
        {
            Node* delet = head;
            head = head->next;
            delete delet;
            sz--;
            return;
        }

        if (index == sz)
        {
            
        }
        
        

        Node *cur = head;

        int pos = 0;
        while (pos < index-1)
        {
            cur = cur->next;
            pos++;
        }

        Node* temp = cur->next;
        cur->next = temp->next;
        if (temp == tail)
        {
            tail = temp;
        }
        
        delete temp;
        sz--;
        
    }

    void print(){
        if (sz == 0)
        {
            cout << -1;
            return;
        }
        else
        {
            Node* cur = head;

            while (cur != NULL)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
        }
    }

    void replace(int index1, int index2) {
        Node *prev = NULL;
        Node* node1 = head;

        for (int i = 0; i < index1; i++)
        {
            prev = node1;
            node1 = node1->next;
        }


        if (prev) prev->next= NULL;
        else head = node1->next;

        if(node1 == tail)  tail = prev;
        node1->next = NULL;

        if (index2 == 0)
        {
            node1->next = head;
            head = node1;
        }

        Node* prev2 = head;
        for (int i = 0; i < index2; i++)
        {
            prev2 = prev2->next;
        }
        node1->next = prev2->next;
        prev2->next = node1;
        
    }

    void reverse(){
        Node* cur = head, *prev = NULL, *next;
        Node* oldhead = head;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        tail = oldhead;
    }

    void cyclec_right(){
        Node *prev = NULL;
        Node *cur = head;

        while (cur->next)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = NULL;
        cur->next = head;
        head = cur;
        tail = prev;        
    }


    void cyclec_left() {
        Node* cur = head;
        head = head->next;
        tail->next = cur;
        tail = cur;
        tail->next = NULL;
    }




};

 
int main(){
    Linked ls;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            ls.insert(x, p); 
        }else if (command == 2){
            int p; cin >> p;
            ls.remove(p);
        }else if (command == 3){
            ls.print();
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            ls.replace(p1, p2);
        }else if (command == 5){
            ls.reverse();
        }else if (command == 6){
            int x; cin >> x;
            for (int i = 0; i < x; i++)
            {
                ls.cyclec_left();
            }
            
        }else if (command == 7){
            int x; cin >> x;
            for (int i = 0; i < x; i++)
            {
                ls.cyclec_right();
            }
            
        }   
    }
    return 0;
}