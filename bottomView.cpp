/* We need to do level order traversal starting root. 
Then keep putting node values in the vector based on
its horizontal distance from root.
                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
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


void getBottomView(Node* node, vector<int>& v, int wl, int wr, int w)
{
    vector<int>::iterator it = v.begin();
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
        v[wd-wl] = n->data;
        if(n->left)
            q.push(make_pair(n->left, wd - 1));
        if(n->right)
            q.push(make_pair(n->right, wd + 1));

    }

    return;
}

vector<int> bottomView(Node* root)
{
    vector<int> v;
    if(!root)
        return v;

    int wl = 0, wr = 0;
    getWidth(root, wl, wr, 0);
    //cout << wl << ":"  << wr << "=" << wr - wl << endl;
    v.insert(v.begin(), wr- wl + 1, 0);

    getBottomView(root, v, wl, wr, 0);
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

    vector<int> v = bottomView(root);

    for(int i: v)
        cout << i << " ";
    cout << endl;
}