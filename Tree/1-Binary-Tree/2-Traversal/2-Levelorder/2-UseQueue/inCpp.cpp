// C++ program to print level order traversal using STL
#include <iostream>
#include <queue>
using namespace std;

// A binary tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// Iterative Method
void printLevelOrder(Node *root) {
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

Node* newNode(int data) {
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main() {
	Node *root 	  = newNode(1);
	root->left	  = newNode(2);
	root->right	  = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	cout << "Level order traversal of binary tree is \n";
	printLevelOrder(root);
	cout << "\n";
	return 0;
}
