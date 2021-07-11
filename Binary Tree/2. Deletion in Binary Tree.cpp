#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class Tree
{
public:
    node *root = NULL;

    void add(int n)
    {
        node *ptr = new node;
        ptr->data = n;
        ptr->left = ptr->right = NULL;
        if (root == NULL)
        {
            root = ptr;
            return;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            else
            {
                temp->left = ptr;
                return;
            }

            if (temp->right != NULL)
                q.push(temp->right);
            else
            {
                temp->right = ptr;
                return;
            }
        }
    }

    void inorder(node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node *findNode(int n)
    {
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp->data == n)
                return temp;
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }

        }

        return NULL;
    }

    node* rightMost()
    {
        node *temp = root;
        node* prev = root;
        while (temp->right != NULL)
            {
                prev = temp;
                temp = temp->right;
            }
            prev->right = NULL;
        return temp;
    }

    void del(int n)
    {
        node* rightMostNode= rightMost();
        node* toBeDeleted = findNode(n);

        toBeDeleted->data = rightMostNode->data;
        free(rightMostNode);
    }
};

int main()
{
    Tree bt;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bt.add(x);
    }
    int x;
    cin>>x;
    bt.inorder(bt.root);
    bt.del(x);
    cout << endl;
    bt.inorder(bt.root);
}