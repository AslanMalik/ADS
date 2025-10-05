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

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {

        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }

        if (node->data > data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }



    int count_triangles(Node *node) {

        if (node == NULL)
        {
            return 0;
        }
        
        if (node->left != NULL && node->right != NULL )
        {
            return 1 + count_triangles(node->left) + count_triangles(node->right);
        }

        else if (node->left != NULL)
        {
            return count_triangles(node->left);
        }
        else if (node->right != NULL)
        {
            return count_triangles(node->right);
        }
        
        
        return 0;
        

        
    }
};




int main() {
    int n; cin >> n;
    BST *bst = new BST();

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        bst->root = bst->insert(bst->root, k);
    }

    cout << bst->count_triangles(bst->root);

    
    return 0;
}