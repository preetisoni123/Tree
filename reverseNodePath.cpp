/* Given a tree and node data, the task to reverse the path to that particular Node.
Examples: 
 

Input: 
            7
         /    \
        6       5
       / \     / \
      4  3     2  1    
Data = 4 
Output: Inorder of tree
7 6 3 4 2 5 1

*/

#include <iostream>
#include <list>

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

void inOrder(Node* n)
{
    if(!n)
        return;

    inOrder(n->left);
    cout << n->data << " ";
    inOrder(n->right);
}

void reverseNodePath(Node* n, int val)
{
    static bool found = false;
    if(!n)
        return;
    static list<Node*> l;

    // Insert element at the back
    // Take it out if not the node
    l.push_back(n);
    if(!found && n->left)
        reverseNodePath(n->left, val);
    if(!found && n->right)
        reverseNodePath(n->right, val);
    if(found)
        return;
    if(n->data != val)
    {
        //cout << "pop back:" <<  l.size() << " ";
        l.pop_back();
    }
    else
    {
        list<Node*>::iterator beg = l.begin();
        list<Node*>::iterator rbeg = l.end();
        rbeg--;
        int tmp, cnt = 0;
        while(cnt < (int)(l.size()/2))
        {   
            //cout << (*beg)->data << "::" << (*rbeg)->data << " ";
            tmp = (*beg)->data;   
            (*beg)->data = (*rbeg)->data;
            (*rbeg)->data = tmp;
            beg++;
            rbeg--;
            cnt++;
        }
        found = true;
    }
}


int main()
{
    Node* root = new Node(20);
   	root->left = new Node(21);
    root->right = new Node(30);
    root->left->right = new Node(22);
    root->left->right->right = new Node(25);
    root->right->right = new Node(5);

    reverseNodePath(root, 30);
    cout << "InOrder: " << endl;
    inOrder(root);
}