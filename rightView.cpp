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

int getHeight(Node* n)
{
    if(!n)
        return 0;

    int hl = getHeight(n->left) + 1;
    int hr = getHeight(n->right) + 1; 
    return hl > hr? hl: hr;
}
void getWidth(Node* n, int& wl, int& wr, int curr)
{
    if(!n)
        return;
    if(wl > curr)
    {
        wl = curr;
        //cout << wl << "wl" << curr << " ";
    }
    if(wr < curr)
    {
        wr = curr;
        //cout << wr << "wr" << curr << " ";
    }
    if(n->left)
    {

        //curr--;
        getWidth(n->left, wl, wr, curr - 1);
    }
    //curr++;
    if(n->right)
    {
        //curr++;
        getWidth(n->right, wl, wr, curr + 1);
    }
}


void getRightView(Node* node, vector<int>& v, int h, int th)
{
    if(!node)
        return;
    v[th] = node->data;
    if(node->left)
        getRightView(node->left, v, h, th + 1);
    if(node->right)
        getRightView(node->right, v, h, th + 1);
    return;
}

vector<int> rightView(Node* node)
{
    vector<int> v;
    int h = getHeight(node);

    v.insert(v.begin(), h, 0); 
    cout << "Height = " << h << endl;
    getRightView(node, v, h, 0);

    for(auto i: v)
        cout << i << " ";
    cout << endl;
    return v;
}

int main()
{
    
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(5);

    vector<int> v = rightView(root);
}