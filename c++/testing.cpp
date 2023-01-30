/*
            1
        2       3
    4     5  
*/

#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node *left, *right;
};

void printLevelOrder(node* root)
{
    if (root == NULL)
        return;
 
    queue<node*> q;
    q.push(root);
 
    while (q.empty() == false) {
        node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}

void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(node* node)
{
    if (node == NULL)
        return;
 
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(node* node)
{
    if (node == NULL)
        return;
 
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

	return 0;
}