#include <iostream>
using namespace std;




class Node{
    public:

    int data, level;
    Node *left, *right;

    Node(int data, int level) {
        this->data = data;
        this->level = level;
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


    Node* insertBegin(Node *node, int x, int level) {

        if (node == NULL)
        {
            node = new Node(x, level);
            return node;
        }
        return NULL;

    }


    Node *insertNode(Node *node, int y, int z, int level) {
        if (z == 0)
        {
            node->left = insertNode(node->left)
        }
        
    }




    Node *insert(Node *node, int x, int y, int z, int level) {


        if (path == 0 && node->data == )
        {
            node->left = insert(node->left, data, level + 1, path);
        }
        else
        {
            node->right = insert(node->right, data, level+1, path);
        }
        return node;        
    }


    void inOrder(Node *node) {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data <<  " ";
        inOrder(node->right);        
    }
};










int main() {


    int n; cin >> n;

    BST *tree = new BST();
    int x, y, z; cin >> x >> y >> z;
    tree->root = tree->insert()

    for (int i = 0; i < n-1; i++)
    {
        int x, y , z; cin >> x >> y > >z;
        tree->root = tree->insert(tree->root, k ,0);
    }
    
    tree->inOrder(tree->root);
    return 0;
}