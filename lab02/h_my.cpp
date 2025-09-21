#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


class Linked{
    public:
    
    int sz;
    Node *head, *tail;

    Linked() {
        sz = 0;
        head = tail = NULL;
    }



    void insert(int value, int index) {
        Node *new_node = new Node(value);


        if (head == NULL)
        {
            head = tail = new_node;
            sz++;
            return;
        }


        if (index == 0)
        {
            new_node->next = head;
            head = new_node;
            sz++;
            return;
        }

        Node* cur = head;
    
        for (int i = 0; i < index-1; i++)
        {
            cur = cur->next;        
        }


        if (sz == index)
        {
            cur->next = new_node;
            tail = new_node;
            new_node->next = NULL;
            sz++;
            return;
        }


        new_node->next = cur->next;
        cur->next = new_node;
        sz++;
        

    }


    void remove(int index) {

        Node* cur = head;

        if (index == 0)
        {
            head = head->next;
            delete cur;
            sz--;
            return;
        }

        for (int i = 0; i < index-1; i++)
        {
            cur = cur->next;
        }
        
        Node* temp = cur->next;
        cur->next = cur->next->next;
        if (temp == tail)
        {
            tail = cur;
        }
        
        delete temp;
        sz--;    

    }


    void print() {
        if (sz == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            Node* cur = head;
            while (cur != NULL)
            {
                cout << cur->data << " ";
                cur = cur->next; 
            }
            cout << endl;
        }
        
        
    }

    void replace(int index1, int index2){
        Node *temp = NULL;

        if (index1 == 0)
        {
            temp = head;
            head = head->next;
            temp->next = NULL;
        }
        else { 
        
            Node* cur = head;

            for (int i = 0; i < index1-1; i++)
            {
                cur = cur->next;
            }

            temp = cur->next;

            cur->next = temp->next;

            temp->next = NULL;
        } 
        
        

        if (index2 == 0)
        {
            temp->next = head;
            head = temp;
        }

        else
        {
            Node* cur2 = head;
            for (int i = 0; i < index2-1; i++)
            {
                cur2 = cur2->next;
            }
            temp->next=cur2->next;
            cur2->next = temp; 
        }
        
        
    }


    void reverse() {
        Node* old_head = head;
        Node* prev = nullptr;
        Node* cur  = head;
        Node* next;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        tail = old_head;
    }


    void cyclic_left(){
        Node* cur = head;
        head = head->next;
        cur->next = NULL;

        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = cur;
        tail = cur;
    }

    void cyclic_right(){
        Node* cur = head;
        while (cur->next->next)
        {
            cur = cur->next;
        }

        Node* temp = cur->next;
        cur->next = NULL;
        tail = cur;

        temp->next = head;
        head = temp;
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
                ls.cyclic_left();
            }
            
        }else if (command == 7){
            int x; cin >> x;
            for (int i = 0; i < x; i++)
            {
                ls.cyclic_right();
            }
            
        }   
    }
    return 0;
}