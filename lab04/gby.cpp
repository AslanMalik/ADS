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

int diametr = 1;

class BST{
    public:

    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node* node,int data) {


        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }

        if (node->data == data)
        {
            return node;
        }
        if (node->data < data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }
        return node;
    }


    int depth(Node *node) {
        if (node == NULL) return 0;

        int l = depth(node->left);
        int r = depth(node->right);
        diametr = max(diametr, l+r);
        return 1 + max(l, r);
    }
};


int main() {
    BST *tree = new BST();
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        tree->root = tree->insert(tree->root,k);
    }

    tree->depth(tree->root);

    cout << diametr + 1;

    
    return 0;
}