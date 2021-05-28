#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(NULL), right(NULL)
    {}
};

int nthInOrderNode(Node* root, int& n)
{
    if(!root)
        return 0;
    static int data;
    if(n && root->left)
        data = nthInOrderNode(root->left, n);
    n--;
    if(!n)
        return root->data;
    
    if(n && root->right)
        data = nthInOrderNode(root->right, n);
    return data;
}

int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(50);

    int n = 4;
    std::cout << nthInOrderNode(root, n) << endl;
}