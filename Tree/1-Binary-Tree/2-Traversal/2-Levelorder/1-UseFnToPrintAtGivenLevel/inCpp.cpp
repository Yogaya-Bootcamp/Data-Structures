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

// Function prototypes
void printGivenLevel(struct Node* root, int level);
int height(struct Node* node);

// Function to print level order traversal in a tree
void printLevelOrder(struct Node* root) {
	int h = height(root);
	int i;
	for(i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

// Print nodes at a given level
void printGivenLevel(struct Node* root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

// Compute the height of a tree - the number of nodes along the longest path from the root node down to the farthest leaf node
int height(struct Node* node) {
	if (node == NULL)
		return 0;
	else {
		// Compute the height of each subtree
		int lheight = height(node->left);
		int rheight = height(node->right);

		// Use the larger one
		if(lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}

int main() {
	struct Node *root	= new Node(1);
	root->left		= new Node(2);
	root->right		= new Node(3);
	root->left->left	= new Node(4);
	root->left->right	= new Node(5);

	cout << "Level order traversal of binary tree is \n";
	printLevelOrder(root);
	cout << "\n";
	return 0;
}
