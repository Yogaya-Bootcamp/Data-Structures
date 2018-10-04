#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node (int data) {
		this->data = data;
		left = right = NULL;
	}
};

// Given a binary tree, print its nodes in preorder
void printPreorder(struct Node* node) {
	if (node == NULL)
		return;
	
	// first print the data of node
	cout << node->data << " ";

	// then recur on left subtree
	printPreorder(node->left);

	// now recur on right subtree
	printPreorder(node->right);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct Node* node) {
	if (node == NULL)
		return;
	
	// first recur on left child
	printInorder(node->left);

	// then print the data of node
	cout << node->data << " ";

	// now recur on right child
	printInorder(node->right);
}

// Given a binary tree, print its nodes according to the 'bottom up' postorder traversal.
void printPostorder(struct Node* node) {
	if (node == NULL)
		return;
	
	// first recur on left subtree
	printPostorder(node->left);
	
	// then recur on right subtree
	printPostorder(node->right);
	
	// now deal with the node
	cout << node->data << " ";
}

int main() {
	struct Node *root 	= new Node(1);
	root->left 	  	= new Node(2);
	root->right		= new Node(3); 
	root->left->left	= new Node(4);
	root->left->right	= new Node(5);

	cout << "Preorder traversal of binary tree is: ";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is: ";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is: ";
	printPostorder(root);
 	cout << "\n";	
	return 0;
}
