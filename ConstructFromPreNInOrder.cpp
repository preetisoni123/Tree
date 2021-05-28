// In Order: Left side of the root=> left subtree, right side of the tree=> right subtree
// PreOrder: Root in the begining of the tree, then left sub tree, followed by wight subtree

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

Node* constructPreIN(int in[], int pre[], int n)
{
    if(n == 0)
        return NULL;
    cout << "Inorder: " << n << " :: ";
    for(int i = 0; i < n; i++)
        cout << in[i] << " ";
    cout << endl<< "Pre: ";
    for(int i = 0; i < n; i++)
        cout << pre[i] << " ";
    cout << endl;

    int p = 0;
    for(; p < n; p++)
        if(in[p] == pre[0])
            break;
    //p = std::find(std::begin(in), in + n, );    
    if(p == n)
        return NULL;
    Node *node = new Node(in[p]);
    int nl = p;
    int nr = n - (p + 1);
    if(nl > 0)
        node->left = constructPreIN(in, pre+1, nl);
    if(nr > 0)
        node->right = constructPreIN(in+ p + 1, pre + p + 1, nr);
    return node;
}

void inOrder(Node* n)
{
    if(!n)
        return;
    inOrder(n->left);
    cout << n->data << " ";
    inOrder(n->right);
}
void postOrder(Node* n)
{
    if(!n)
        return;
    postOrder(n->left);
    postOrder(n->right);
    cout << n->data << " ";
}

int main()
{
    /*Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(5);
    */
    int in[] = {1, 6, 8, 7};
    int pre[] = {1, 6, 7, 8};
    Node* root = constructPreIN(in, pre, 4);

    inOrder(root);
    cout << endl;
    return 0;
}