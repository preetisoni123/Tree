#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    char v;
    Node* left;
    Node* right;

    Node(char v): v(v), left(NULL), right(NULL)
    {}
};

void inOrder(Node* n)
{
    if(!n)
        return;
    inOrder(n->left);
    cout << n->v << " ";
    inOrder(n->right);
}

bool isOperator(char tmp)
{
    if(tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^')
        return true;
    return false;
}

Node* constructExpressionTree(char postFix[])
{
    stack<Node*> st;

    int i = 0;
    while(postFix[i] != '\0')
    { 
        if(isOperator(postFix[i]))
        {
            Node* t = new Node(postFix[i]);
            t->right = st.top();
            st.pop();
            t->left = st.top();
            st.pop();
            st.push(t);
        }
        // Operand
        else
            st.push(new Node(postFix[i]));

        i++;
    }
    return st.top();
}

//int calculate(Node* A, Node* B, Node* op)
int calculate(int A, int B, char op)
{
    int tmp = 0;
    switch(op)
    {
        case '+': tmp = A + B;
                break;
        case '-': tmp = A - B;
                break;
        case '*': tmp = A * B;
                break;
        case '/': tmp = A / B;
                break;
        
    }
    return tmp;
}

int calculateExpressionTree(Node* n)
{
    if(!n)
        return -1;
    if(isOperator(n->v))
    {
        int a = 0, b = 0;
        if(n->left)
            a = calculateExpressionTree(n->left);
        if(n->right)
            b = calculateExpressionTree(n->right);
        return calculate(a, b, n->v);
    }
    else
        return (n->v - '0');
}

int main()
{
    //char in[] = "ab+ef*g*-";
    char in[] = "45+23*1*-";
    Node* n = constructExpressionTree(in);
    inOrder(n);
    cout << endl << "Value of the expression: " << calculateExpressionTree(n) << endl;
    return 0;
}