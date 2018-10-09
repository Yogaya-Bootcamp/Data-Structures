class Node {
	int data;
	Node left, right;
	
	public Node(int data) {
		this.data = data;
		left = right = null;
	}
}

class BinaryTree {
	Node root;

	BinaryTree() {
		root = null;
	}

	
	// Given a binary tree, print its nodes in preorder
	void printPreorder(Node node) {
		if (node == null)
			return;
	
		// first print the data of node
		System.out.print(node.data + " ");

		// then recur on left subtree
		printPreorder(node.left);

		// now recur on right subtree
		printPreorder(node.right);
	}

	// Given a binary tree, print its nodes in inorder
	void printInorder(Node node) {
		if (node == null)
			return;
	
		// first recur on left child
		printInorder(node.left);

		// then print the data of node
		System.out.print(node.data + " ");

		// now recur on right child
		printInorder(node.right);
	}

	// Given a binary tree, print its nodes according to the 'bottom up' postorder traversal.
	void printPostorder(Node node) {
		if (node == null)
			return;
	
		// first recur on left subtree
		printPostorder(node.left);
	
		// then recur on right subtree
		printPostorder(node.right);
	
		// now deal with the node
		System.out.print(node.data + " ");
	}

	// Wrappers over above recursive functions
	void printPreorder() { printPreorder(root); }
	void printInorder() { printInorder(root); }
	void printPostorder() { printPostorder(root); }

	// Driver method
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);

	System.out.println("Preorder traversal of binary tree ");
		tree.printPreorder();	
	
	System.out.println("\nInorder traversal of binary tree ");
		tree.printInorder();

	System.out.println("\nPreorder traversal of binary tree ");
		tree.printPostorder();

	System.out.println();	
	}
}
