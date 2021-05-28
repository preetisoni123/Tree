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

bool symmetricTree(Node* r1, Node* r2)
{
    if(!r1 && !r2)
        return true;
    else if (!r1 || !r2)
        return false;
    return (r1->data == r2->data && symmetricTree(r1->left, r2->right) 
        && symmetricTree(r1->right, r2->left));
}



int main()
{
    Node* root = new Node(1);
   	root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(8);

    cout << symmetricTree(root->left, root->right) << endl;
}