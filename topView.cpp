/* We need to do level order traversal starting root. 
Then keep putting node values in the vector based on
its horizontal distance from root.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

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


void getTopView(Node* node, vector<int>& v, vector<bool> b, int wl)
{
    queue<pair<Node*, int>> q;
    if(!node)
        return;
    q.push(make_pair(node, 0));
    while(!q.empty())
    {
        Node* n;
        int wd;
        tie(n, wd) = q.front();
        q.pop();
        if(!b[wd - wl])
        {
            v[wd-wl] = n->data;
            b[wd - wl] = true;
        }
        if(n->left)
            q.push(make_pair(n->left, wd - 1));
        if(n->right)
            q.push(make_pair(n->right, wd + 1));

    }

    return;
}

vector<int> topView(Node* root)
{
    vector<int> v;
    if(!root)
        return v;

    int wl = 0, wr = 0;
    getWidth(root, wl, wr, 0);
    //cout << wl << ":"  << wr << "=" << wr - wl << endl;
    v.insert(v.begin(), wr- wl + 1, 0);
    vector<bool> b;
    b.insert(b.begin(), wr - wl + 1, false);

    getTopView(root, v, b, wl);
    return v;
}


int main()
{
    //Node *root = NULL;
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->left->right->right = new Node(25);
    root->right->right = new Node(5);

    vector<int> v = topView(root);

    for(int i: v)
        cout << i << " ";
    cout << endl;
}