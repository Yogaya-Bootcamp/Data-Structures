// C++ program to insert element in binary tree
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

// Function to create a new node of tree and return pointer
struct Node* newNode(int data) {
	struct Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Inorder traversal of a binary tree
void inorder(struct Node *temp) {
	if(!temp)
		return;

	inorder(temp->left);
	cout << temp->data << " ";
	inorder(temp->right);
}

void insert(struct Node* temp, int key) {
	queue<struct Node *> q;
	q.push(temp);

	while(!q.empty()) {
		struct Node* temp = q.front();
		q.pop();

		if(!temp->right) {
			temp->right = newNode(key);
			break;
		} else
			q.push(temp->right);

		if(!temp->left) {
			temp->left = newNode(key);
			break;
		} else
			q.push(temp->left);
	}
}

int main() {
	struct Node* root 		= newNode(10);
	root->left			= newNode(11);
	root->right			= newNode(9);
	root->left->left		= newNode(7);
	root->right->right		= newNode(8);

	cout << "Inorder traversal before insertion: ";
	inorder(root);

	int key = 12;
	insert(root, key);

	cout << endl;
	
	cout << "Inorder traversal after insertion: ";
	inorder(root);
	cout << endl;
	return 0;
}
