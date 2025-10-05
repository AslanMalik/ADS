#include <iostream>
using namespace std;


class Node{
    public:

    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class BST{
    public:

    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node* node, int data) {
        if (node == NULL)
        {
            Node* new_node = new Node(data);
            return new_node;
        }

        if (data >= node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }
        return node;
    }


    Node *find_node(Node* node, int number) {

        if (!node) return nullptr;


        if (number == node->data)
        {
            return node;
        }

        if (number > node->data)
        {
            node->right = find_node(node->right, number);
        }
        else
        {
            node->left =  find_node(node->left, number);
        }
        return node; 
    }

    int in_order(Node *node) {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + in_order(node->left) + in_order(node->right);
        }
    
};


int main() {
    int n;
    cin >> n;

    BST* bst = new BST();


    for (int i = 0; i < n; i++)
    {
        int number; cin >> number;
        bst->root = bst->insert(bst->root, number);
    }
    

    int find_number; cin >> find_number;

    Node* node = bst->find_node(bst->root, find_number);

    int cnt = 0;

    int answer = bst->in_order(node);

    cout << answer;


    return 0;
}