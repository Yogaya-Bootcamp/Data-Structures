// C++ program to delete element in binary tree
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data) {
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;	
}

void inorder(struct Node* node) {
	if(!node)
		return;
	
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void deleteDeepest(struct Node* root, struct Node* d_node) {
	queue<struct Node*> q;
	q.push(root);
	
	struct Node* temp;
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		
		if(temp->right) {
			if(temp->right == d_node) {
				temp->right = NULL;
				delete(d_node);
				return;
			} else
				q.push(temp->right);
		}
		
		if(temp->left) {
			if(temp->left == d_node) {
				temp->left = NULL;
				delete(d_node);
				return;
			} else
				q.push(temp->left);
		}	
	}
}

void deletion(struct Node* root, int key) {
	queue<struct Node*> q;
	q.push(root);

	struct Node *temp;
	struct Node *key_node = NULL;

	// Do level order traversal to find deepest node (temp) and node to be deleted (key_node)
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		
		if(temp->data == key)
			key_node = temp;
		
		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}
	
	int x = temp->data;
	deleteDeepest(root, temp);
	key_node->data = x;
}

int main() {
	struct Node* root 	= newNode(10);
	root->left		= newNode(11);
	root->right		= newNode(9);
	root->left->left	= newNode(7);
	root->left->right	= newNode(12);
	root->right->left 	= newNode(15);
	root->right->right	= newNode(8);

	cout << "Inorder traversal before deletion: ";
	inorder(root);

	int key = 11;
	deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion: ";
	inorder(root);
	cout << endl;	
	return 0;
}
