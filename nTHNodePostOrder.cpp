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

int nTHNodePostOrder(Node* root, int& n)
{
    static int ret = 0;
    if(!root)
        return 0;
    if(!ret && root->left)
        ret = nTHNodePostOrder(root->left, n);
    if(!ret && root->right)
        ret = nTHNodePostOrder(root->right, n);
    
    n--;
    //cout << n << " ";
    if(!n)
        ret = root->data;
    return ret;
}

int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(50);

    int n = 6;
    cout << nTHNodePostOrder(root, n) << endl;
}