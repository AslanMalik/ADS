#include <iostream>
using namespace std;

struct Node {
	int data;
    int cnt;
	Node* left;
	Node* right;


	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
        this->cnt = 1;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* insert(Node* root, int data) {
	if (root == NULL) {
        Node* new_node = new Node(data);
		return new_node;
	}

    if (root->data == data)
    {
        root->cnt++;
        return root;
    }
    if (root->data > data) {
            root->left = insert(root->left, data);
        } 
    else {
            root->right = insert(root->right, data);
        }
    return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
    
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;

	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;

	} else {
        if (root->cnt > 1)
        {
            root->cnt--;
            return root;
        }
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
            if (root->cnt == 1)
            {
            	Node* temp = root->left;
			    delete root;
			    return temp;        
            }
            else
            {
                root->cnt--;
                return root;
            }
            
		} else if (root->left == NULL) {
            if (root->cnt == 1)
            {
            	Node* temp = root->right;
			    delete root;
			    return temp;
            }
            else
            {
                root->cnt--;
                return root;
            }
            
		} else {

            if (root->cnt == 1)
            {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                return root;
            }
            else
            {
                root->cnt--;
                return root;
            }
            
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int cnt(Node* root, int x) {
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == x)
    {
        return root->cnt;
    }
    else if (root->data > x)
    {
        return cnt(root->left, x);
    }
    return cnt(root->right, x);
       
}

int main() {
    int n; cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        string query; int data;
        cin >> query >> data;

        if (query == "insert")
        {
            root = insert(root, data);
        }
        else if (query == "cnt")
        {
            cout << cnt(root, data) << endl;
        }
        else if (query == "delete")
        {
            root = deleteNode(root, data);
        }
        
        
        
    }
    
    return 0;
}