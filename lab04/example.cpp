#include <iostream>
using namespace std;


class Node{
    public:

    int data, cnt;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->cnt = 1;
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

        if (node->data == data)
        {
            node->cnt++;
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


    int find_cnt(Node* node, int data) {
        if (node->data == data)
        {
            return node->cnt;
        }

        if (node->data > data)
        {
            return find_cnt(node->left, data);
        }
        else
        {
            return find_cnt(node->right, data);
        }
        return 0;
    }


    void delete_node(Node *node, int data){ 
        
    }


};

int main() {
    int n; cin >> n;
    int number = pow(2, n);
    vector<int> arr;

    for (int i = 0; i < number-1; i++)
    {
        int k; cin >> k; arr.push_back(k); 
    }

    sort(arr.begin(), arr.end());

    shuffle(0, number-2, arr);
    
    
    
    return 0;
}