#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(NULL), right(NULL)
    {}
};

bool isBST(Node* node)
{
    static int pre = -1;
    if(!node)
        return true;

    if(!isBST(node->left))
        return false;

    if(node->data > pre)
    {
        pre = node->data;
    }
    else return false;

    if(!isBST(node->right))
        return false;
    
    return true;
}

int main()
{
    
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(5);

    cout << "isBST: " << isBST(root) << endl;
}