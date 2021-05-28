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

Node* constructFromPreOrder(int pre[], int n)
{
    if(!n)
        return NULL;
    //cout << n << " : ";
    //for(int i = 0; i < n; i++)
    //    cout << pre[i] << " ";
    //cout << endl;
    Node* tmp = new Node(pre[0]);
    int nl = 1;
    int nr = 0;

    while(nl < n && pre[nl] < pre[0])
        nl++;

    nl--;    
    nr = n - (nl + 1);
    //cout << " : " << nl << ", " << nr << endl;
    tmp->left = constructFromPreOrder(pre+1, nl);
    tmp->right = constructFromPreOrder(pre + nl + 1, nr);

    return tmp;
}

void postOrder(Node* root)
{
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node* root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


int main()
{
    int pre[] = {10, 5, 1, 7, 6, 9, 40, 50};

    Node* root = constructFromPreOrder(pre, 8);
    cout << "postOrder: ";
    postOrder(root);
    cout << endl << "inOrder: ";
    inOrder(root);
}