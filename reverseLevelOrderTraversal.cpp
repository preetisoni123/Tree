#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data):data(data), left(NULL), right(NULL)
    {}
};

void levelOrder(Node* node, vector<int>& v)
{
    // Level order using queue
    // If not using queue, then get height and in a for loop
    // check for nodes in the given height
    queue<Node*> q;

    if(!node)
        return;
    
    q.push(node);
    while(!q.empty())
    {
        node = q.front();
        v.push_back(node->data);
        q.pop();

        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

void reverseLevelOrder_stack(Node* node, stack<int>& s)
{
    queue<Node*> q;

    if(!node)
        return;
    
    q.push(node);
    while(!q.empty())
    {
        node = q.front();
        s.push(node->data);
        //cout << node->data << " ";
        q.pop();

        if(node->right)
            q.push(node->right);
        if(node->left)
            q.push(node->left);
    }
    //cout << endl;
}

void reverseLevelOrder_vector(Node* node, vector<int>& tmp)
{
    queue<Node*> q;

    if(!node)
        return;
    
    q.push(node);
    vector<int>::iterator it;
    while(!q.empty())
    {
        node = q.front();
        tmp.insert(it, node->data);
        it = tmp.begin();
        q.pop();

        if(node->right)
            q.push(node->right);
        if(node->left)
            q.push(node->left);
    }
}


int main()
{
    Node* root = new Node(20);
   	root->left = new Node(10);
    root->right = new Node(30);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(50);

    // Level order 
    vector<int> v;
    levelOrder(root, v);

    cout << "Level Order: ";
    for(auto i: v)
        cout << i << " ";
    cout << endl;

    // Reverse level order - using vector
    vector<int> tmp;
    reverseLevelOrder_vector(root, tmp);

    cout << "Level Order: ";
    for(auto i: tmp)
        cout << i << " ";
    cout << endl;
    // Reverse level order
    stack<int> s;
    reverseLevelOrder_stack(root, s);

    cout << "Reverse Level Order:  ";// << s.size() << " ";
    int val;
    while(!s.empty())
    {
        val = s.top();
        s.pop();
        cout << val << " ";
    }

}