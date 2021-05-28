#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int data): data(data), left(NULL), right(NULL), next(NULL)
    {}
};

Node* populateInOrderSuccessor(Node* root)
{
    static Node* prev = NULL;
    static Node* first = NULL;
    if(!root)
        return first;
    //static bool found = false;
    //static int data = -1;

    if(root->left)
    {
        populateInOrderSuccessor(root->left);
    }

    if(prev)
    {
        prev->next = root;
        //cout << prev->data << ":" << root->data << " ";
    }
    else
    {
        //cout << "first: " << root->data << " ";
        first = root;
    }
    prev = root;

    if(root->right)
    {
        populateInOrderSuccessor(root->right);
    }
    return first;
}

int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(50);

    //int n = 30;
    Node* first = populateInOrderSuccessor(root);
    //cout << "output: " << first->data << endl;
    Node* tmp = first;
    while(tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}