#include <iostream>
#include <vector>

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

int inOrderSuccessor(Node* root, int n)
{
    if(!root)
        return 0;
    static Node* prev = NULL;
    static bool found = false;
    static int data = -1;

    if(!found &&root->left)
    {
        data = inOrderSuccessor(root->left, n);
    }

    if(!found)
    {
        if(prev && prev->data == n)
        {
            found = true;
            return root->data;
        }
        prev = root;
    }

    if(!found && root->right)
    {
        data = inOrderSuccessor(root->right, n);
    }
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

    int n = 30;
    std::cout << inOrderSuccessor(root, n) << endl;
}