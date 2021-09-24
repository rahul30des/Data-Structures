#include<iostream>
#include<algorithm>

using namespace std;

class Node {
    public:    
        int value;
        Node *left, *right;
        Node(int val) {
            value = val;
            left = right = NULL;
        }
};


void CreateBST(Node **root) {
    *root = new Node(10);
    Node *tmp = *root;
    tmp->left = new Node(7);
    tmp->right = new Node(12);
    tmp->left->left = new Node(5);
    tmp->left->right = new Node(8);
    tmp->right->left = new Node(11);
    tmp->right->right = new Node(3);
}

bool IsBST(Node *root, int min, int max) {
    if(root == NULL) {
        return true;
    }
    return ((root->value > min && root->value < max) && IsBST(root->left, min, root->value) && IsBST(root->right, root->value, max));
}

// Main Function
int main() {
    Node *root = NULL;
    CreateBST(&root);
    cout<<boolalpha<<IsBST(root, INT_MIN, INT_MAX)<<endl;
}
