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



class Tree{
    public:

    Node* insert(Node *node, int data){
        if (node == NULL)
        {
            Node *new_node = new Node(data);
            return new_node;
        }
        else if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;        
    }


    void in_order(Node *node) {

        if (node == NULL)
        {
            return;
        }
        
        in_order(node->left);
        cout << node->data << " ";
        in_order(node->right);
    }

    Node *find_min(Node *node) {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }


    Node *delete_node(Node *node, int data) {
        if (node == NULL)
        {
            return NULL;
        }
        else if (node->data < data)
        {
            node->left = delete_node(node->left, data);
        }
        else if (node->data > data)
        {
            node->right = delete_node(node->right, data);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                return NULL;
            }
            else if (node->left == NULL)
            {
                node = node->right;
            }
            else if (node->right == NULL)
            {
                node = node->left;
            }
            else
            {
                Node *tmp = find_min(node->right);
                node->data = tmp->data;
                node->right = delete_node(node->right, tmp->data);
    
            }
            
            
            
        }
        return node;
        
        
        
    }


}







int main() {
    return 0;
}





