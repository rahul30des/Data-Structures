#include<iostream>
#include<algorithm>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

void createBST(Node **root) {
    *root = new Node(10);
    Node *temp = *root;
    temp->left = new Node(8);
    temp->right = new Node(12);
    temp->left->left = new Node(7);
    temp->left->right = new Node(9);
    temp->right->left = new Node(11);
    temp->right->right = new Node(5);
}

bool isBSTUtil(Node *root, int min, int max) {
    if(root == NULL) {
        return true;
    }
    if(((root->value > min) && (root->value < max)) && isBSTUtil(root->left, min,
                                                    root->value) &&
       isBSTUtil(root->right, root->value, max)) {
        return true;
    } else {
        return false;
    }      
}


bool isBST(Node *root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Main
int main() {
    Node *root;
    createBST(&root);
    cout<<boolalpha<<isBST(root);
    return 0;
}
