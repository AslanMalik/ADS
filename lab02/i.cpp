#include <iostream>
using namespace std;

class Node{
    public:
    string data;
    Node *next, *prev;

    Node(string data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};



class DoublyLinked{
    public:
    int sz;
    Node *head, *tail;

    DoublyLinked() {
        sz = 0;
        head = NULL;
        tail = NULL;
    }


    void add_front(string s) {
        Node *new_node = new Node(s);
        if (sz == 0)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        cout << "ok" << endl;
        sz++;
    }


    void add_back(string s) {
        Node *new_node = new Node(s);
        if (sz == 0)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;       
        }
        cout << "ok" << endl;
        sz++;
    }

    void erase_front() {

        if (head == NULL)
        {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = head;

        cout << temp->data << endl;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        
        
        delete temp;
        sz--;
    }

    void erase_back(){
        if (tail == NULL)
        {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = tail;

        cout << temp->data << endl;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        
        
        delete temp;
        sz--;
    }

    void front() {
        if (head == NULL)
        {
            cout << "error" << endl;
            return;
        }
        
        cout << head->data << endl;
    }

    void back() {
        if (tail == NULL)
        {
            cout << "error" << endl;
            return;
        }
        
        cout << tail->data << endl;
    }

    void clear() {
        Node* current = head;
        while (current!= NULL)
        {
            Node* new_node = current->next;
            delete current;
            current = new_node;
        }

        head = NULL;
        tail = NULL;
        sz = 0;
        cout << "ok" << endl;
    }

};


int main() {
    DoublyLinked task;
    while (true)
    {
        string s;
        cin >> s;

        
        if (s == "add_front")
        {
            string x;
            cin >> x;
            task.add_front(x);
        }

        else if (s == "add_back")
        {
            string x;
            cin >> x;
            task.add_back(x);
        }

        else if (s == "front") {
            task.front();
        }

        else if (s == "back") {
            task.back();
        }

        else if (s == "erase_front")
        {
            task.erase_front();
        }

        else if (s == "erase_back")
        {
            task.erase_back();
        }
        else if (s == "clear")
        {
            task.clear();
        }
        else if (s == "exit")
        {
            cout << "goodbye";
            break;
        }
        
    }
    
    return 0;
}