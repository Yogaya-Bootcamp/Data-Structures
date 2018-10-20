#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
	char *data;
	struct Node *left, *right;
	Node(char *data) {
		this->data = data;
		left = right = NULL;
	}
};

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

// Given a binary tree, print its nodes in preorder
vector<string> preorder(struct Node* node, vector<string> & output) {
	if (node == NULL)
		return output;
	
	// first print the data of node
	// cout << node->data << " ";
	output.push_back(node->data);

	// then recur on left subtree
	preorder(node->left, output);

	// now recur on right subtree
	preorder(node->right, output);

	return output;
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

// Iterative function for inorder tree traversal
void printInorderUsingStack(struct Node* root) {
	stack<Node *> s;
	Node *cur = root;

	while (cur != NULL || s.empty() == false) {
		// Reach the left most Node of the cur Node
		while(cur != NULL) {
			// Place pointer to a tree node on the stack before traversing the node's left subtree
			s.push(cur);
			cur = cur->left;
		}
		// cur must be NULL at this point.
		cur = s.top();
		s.pop();
		
		cout << cur->data << " ";

		// we have visited the node and its left subtree. Now it's right subtree's turn
		cur = cur->right;
	}
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

// Function to print level order traversal in a tree
void printLevelorder(struct Node* root) {
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

// Iterative Method
void printLevelorderUsingQueue(struct Node *root) {
	if(root == NULL)
		return;
	
	// Create an empty queue for level order traversal
	queue<Node *> q;

	// Enqueue root and initialize height
	q.push(root);

	while(q.empty() == false) {
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();		
		
		// Enqueue left child
		if(node->left != NULL)
			q.push(node->left);

		// Enqueue right child
		if(node->right != NULL)
			q.push(node->right);
	}
}

struct Node* createTree(struct Node *node, char* arr[], int n, int i) {
	if (i < n) {
		if (strncmp(arr[i], "-", n) == 0)
			return node;

		node = new Node(arr[i]);
		struct Node *leftNode  = createTree(node->left, arr, n, 2 * i + 1);
		struct Node *rightNode = createTree(node->right, arr, n, 2 * i + 2);
		node->left  = leftNode;
		node->right = rightNode;

		return node;
	} else
		return NULL;
}

// BST: Search a given key in a given BST
struct Node* search(struct Node* root, string key) {
	// Base cases: root is null or key is present at root
	if (root == NULL || root->data == key)
		return root;	

	// Key is greater than root's key
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

// BST: Insert a new node with given key in BST
struct Node* insert(struct Node* node, char * key) {
	// if the tree is empty, return a new node
	if (node == NULL)
		return new Node(key);

	// otherwise, recurse down the tree
	if (strncmp(key, node->data, 10) < 0)
		node->left = insert(node->left, key);
	else if (strncmp(key, node->data, 10) > 0)
		node->right = insert(node->right, key);
	
	return node;
}

// Given a non-empty BST, return the node with minimum key value found in that tree. Note that the entire tree does not need to be searched.
struct Node * minValueNode(struct Node* node) {
	struct Node* current = node;

	// loop down to find the leftmost leaf
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Given a BST and a key, this function deletes the key and returns the new root
struct Node* deleteNode(struct Node *root, char* key) {
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the root's data, then it lies in left subtree
	if (strncmp(key,  root->data, 10) < 0)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's data, then it lies in right subtree
	else if (strncmp(key,  root->data, 10) > 0)
		root->right = deleteNode(root->right, key);

	// if key is same as the root's data, then this is the node to be deleted
	else {
		// node with only one child or no child
		if (root->left == NULL) {
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct Node *temp = root->left;
			free(root);
			return temp;
		}

		// Node with two children: Get the inorder successor (smallest) in right subtree
		struct Node* temp = minValueNode(root->right);
		
		// Copy the inorder successor's content to this Node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);		
	}

	return root;
}

void printHeightAndTraversals(struct Node* root) {
	cout << "Height of the tree: " << height(root);
	
	cout << endl << "LevelOrder: ";
	printLevelorderUsingQueue(root);

	cout << endl << "PreOrder: ";	
	vector<string> preorderOutput;
	preorderOutput  = preorder(root, preorderOutput);
	for (int i = 0; i < preorderOutput.size(); i++)
		cout << preorderOutput[i] << " ";

	cout << endl << "InOrder: ";
	printInorder(root);

	cout << endl << "PostOrder: ";	
	printPostorder(root);
	cout << endl;	
}

int main(int argv, char* argc[]) {
	struct Node *root = NULL;
	
	// insert - construct BST from input elements
	for(int i = 0; i < argv-2; i++)
		root = insert(root, argc[i + 1]);	
	
	printHeightAndTraversals(root);
		
	// search/delete key
	string key = argc[argv-1];

	struct Node* matchedNode = search(root, key);
	if(matchedNode != NULL)
		cout << "\nKey is present.";
	else
		cout << "\nKey is not present.";
	
	cout << endl;

	// delete key from BST
	char *delKey = "60";
	root = deleteNode(root, delKey);
	printHeightAndTraversals(root);
	
	return 0;
}
