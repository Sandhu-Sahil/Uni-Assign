#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int val)
		: val(val)
		, left(NULL)
		, right(NULL)
	{
	}
};

void insert(Node*& root, int key)
{
	Node* node = new Node(key);
	if (!root) {
		root = node;
		return;
	}
	Node* prev = NULL;
	Node* temp = root;
	while (temp) {
		if (temp->val > key) {
			prev = temp;
			temp = temp->left;
		}
		else if (temp->val < key) {
			prev = temp;
			temp = temp->right;
		}
	}
	if (prev->val > key)
		prev->left = node;
	else
		prev->right = node;
}

bool search(Node* root, int key)
{
    if (root == NULL)
		return false;

	if ((int) root->val == key)
		return true;

	if (key < (int) root->val)
		return search(root->left, key);

	else if (key > (int) root->val)
		return search(root->right, key);

	return false;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

Node *minValueNode(Node *node) {
  Node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

Node *deleteNode(Node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->val)
    root->left = deleteNode(root->left, key);
  else if (key > root->val)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    Node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->val = temp->val;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->val);
  }
  return root;
}

int main()
{
	Node* root = NULL;
	insert(root, 30);
	insert(root, 50);
	insert(root, 15);
	insert(root, 20);
	insert(root, 10);
	insert(root, 40);
	insert(root, 60);

	printInorder(root);

	root = deleteNode(root, 20);
	cout<<endl;
	printInorder(root);
	cout<<endl;

	cout<<search(root, 20)<<endl;
	cout<<search(root, 30)<<endl;

	return 0;
}