/* Given a Binary Tree find the length of the longest path 
which comprises of nodes with consecutive values in increasing
 order. Every node is considered as a path of length 1.

In below diagram binary tree with longest consecutive path(LCP) are shown :
3

       1
    /     \
   2       5
  /  \    / \
 3    5  6   7
*/

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


int longestConsecutiveSequence(Node* n, int num, int curr)
{
    static int max = 0;
    if(!n)
        return max;
    if(num == n->data)
    {
        curr++;
        if(curr > max)
            max = curr;
    }
    longestConsecutiveSequence(n->left, n->data + 1, curr);
    longestConsecutiveSequence(n->right, n->data + 1, curr);

    return max;
}


int main()
{
    //Node *root = NULL;
    Node* root = new Node(20);
   	root->left = new Node(21);
    root->right = new Node(30);
    root->left->right = new Node(22);
    root->left->right->right = new Node(25);
    root->right->right = new Node(5);

    cout << longestConsecutiveSequence(root, root->data, 0);
}