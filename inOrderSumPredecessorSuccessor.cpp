#include <iostream>
#include <vector>

using namespace std;

/*
Given a binary tree containing n nodes. The problem is to replace
each node in the binary tree with the sum of its inorder 
predecessor and inorder successor.

Input :          1
               /   \
              2     3
            /  \  /  \
           4   5  6   7

Output :        11
              /    \
             9      13
            / \    /  \
           2   3   4   3
*/

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(NULL), right(NULL)
    {}
};

void inOrder(Node* root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrderInserInVector(Node* root, vector<int>& v)
{
    if(!root)
        return;
    inOrderInserInVector(root->left, v);
    v.push_back(root->data);
    inOrderInserInVector(root->right, v);
}

void inOrderSum(Node* root, vector<int>& v, int& i)
{
    if(!root)
        return;
    inOrderSum(root->left, v, i);
    root->data = v[i - 1] + v[i + 1];
    i++;
    inOrderSum(root->right, v, i);
}

void inOrderSumPredecessorSuccessor(Node* root)
{
    vector<int> v;
    v.push_back(0);

    // Create array with inOrder values in vector
    inOrderInserInVector(root, v);

    // Do the sum
    v.push_back(0);
    int i = 1;
    inOrderSum(root, v, i);
}

int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(50);

    inOrderSumPredecessorSuccessor(root);
    inOrder(root);
}