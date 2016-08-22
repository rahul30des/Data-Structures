#include<iostream>
#include<algorithm>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    // Default Constructor
    Node () {}
    // Parameterized Constructor
    Node (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
// Should be rewritten to make the attributes private and below functions public for the class
Node* insert(Node *root, int value) {
    if (!root) {
        root = new Node();
        root->data = value;
        root->right = NULL;
        root->left = NULL;
    } else if(value <= root->data) {
        root->left = insert(root->left, value); 
    } else if (value >= root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// InOrder Traversal
void inorder(Node *root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout<<"\t"<<root->data;
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root ) {
        return;
    }
    cout<<"\t"<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<"\t"<<root->data;
}

// Main Function
int main() {
   Node *obj = NULL;
   obj = insert(obj, 5);
   obj = insert(obj, 4);
   obj = insert(obj, 6); 
   obj = insert(obj, 3);
   obj = insert(obj, 8);
   obj = insert(obj, 7);
   obj = insert(obj, 9);

    cout<<"Inorder: "<<endl;
    inorder(obj);
    cout<<endl;
    cout<<"Preorder: "<<endl;
    preorder(obj);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    postorder(obj);

    return 0;
}
