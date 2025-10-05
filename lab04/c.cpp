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
            return find_node(node->right, number);
        }
        else
        {
            return find_node(node->left, number);
        }
        return node; 
    }

    // In-order traversal - gives sorted output
    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Pre-order traversal
    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal
    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
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


    bst->preOrder(node);

    return 0;
}