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

    Node* root;


    BST(){
        root = NULL;
    }



    Node* insert(Node *node, int data) {
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


    bool check_result(Node* node, string path) {


        if (node == NULL)
        {
            return false;
        }
        

        
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == 'L')
            {
                if (node->left != NULL)
                {
                    node = node->left;
                }
                else
                {
                    return false;
                }            
            }

            else
            {
                if (node->right != NULL)
                {
                    node = node->right;
                }
                else
                {
                    return false;
                }
                
                
            }
        }


        return true;
        
    }

};



int main() {

    BST* bst = new BST();


    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        bst->root = bst->insert(bst->root, number);
    }


    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        //bool flag = check_result(bst->root, s);

        if (bst->check_result(bst->root, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
        
        
    }
    
    





    return 0;
}