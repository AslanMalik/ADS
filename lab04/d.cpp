#include <iostream>
using namespace std;


class Node{
    public:

    int data, level;
    Node *left, *right;

    Node(int data, int level) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->level = level;
    }
};


class BST{
    public:

    Node* root;

    BST(){
        root = NULL;
    }

    Node *insert(Node* node, int data, int level) {
        if (node == NULL)
        {
            node = new Node(data, level);
            return node;
        }

        if (node->data > data)
        {
            node->left = insert(node->left, data, level + 1 );
        }
        else
        {
            node->right = insert(node->right, data, level + 1 );
        }
        return node;
    }

    int getHeight(Node *node) {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
        
    }

    int sum_of_all_level(Node* node, int index) {


        if (node == NULL)
        {
            return 0;
        }
        
        

        int sum_all = 0;
        if (index == node->level)
        {
            sum_all += node->data;
        }

        sum_all += sum_of_all_level(node->left, index);
        sum_all += sum_of_all_level(node->right, index);
        

        return sum_all;
        
    }


};





int main() {

    BST *tree = new BST();

    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;

        tree->root = tree->insert(tree->root, k, 0);
    }


    int height = tree->getHeight(tree->root);

    cout << height << endl;

    for (int i = 0; i < height; i++)
    {
        cout << tree->sum_of_all_level(tree->root, i) << " ";
    }
    
    


    return 0;
}