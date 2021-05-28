#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data):data(data), left(NULL), right(NULL)
    {}
};

void preOrder(Node* node)
{
    if(!node)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node)
{
    if(!node)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node)
{
    if(!node)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);

    cout << "preOrder: ";
    preOrder(root);
    cout << endl;
    cout << "inOrder: ";
    inOrder(root);
    cout << endl;
    cout << "postOrder: ";
    postOrder(root);
    cout << endl;
}