#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:

    Node *root;

    BST(){
        root=NULL;
    }


    Node *insert(Node* node, int data) {
        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }

        if (node->data > data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }
        return node;
    }


    void in_order(Node *node, int &sum) {
        if (node == NULL)
        {
            return;
        }
        

        in_order(node->left, sum);
        sum += node->data;
        cout << sum << " ";
        in_order(node->right, sum);
    }
};

int main() {



    BST *bst = new BST();

    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        bst->root = bst->insert(bst->root, k);
    }

    int sum = 0;
    bst->in_order(bst->root, sum);
    
    return 0;
}