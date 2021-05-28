#include <iostream>
#include <vector>

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

void leftView(Node* node, int level)
{
    static int maxLevel = 0;
    if(!node)
        return;
    if(level >= maxLevel)
    {
        cout << node->data << " ";
        maxLevel++;
    }
    if(node->left)
        leftView(node->left, level + 1);
    if(node->right)
        leftView(node->right, level + 1);
    return;
}

int main()
{
    
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(5);

    leftView(root, 0);
}