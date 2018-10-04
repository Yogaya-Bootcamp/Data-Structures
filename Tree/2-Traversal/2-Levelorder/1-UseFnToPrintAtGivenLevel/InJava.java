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
	
	// Function to print level order traversal in a tree
	void printLevelOrder() {
		int h = height(root);
		System.out.println("Height of tree: " + h);
		int i;
		for(i = 1; i <= h; i++)
			printGivenLevel(root, i);
	}

	// Print nodes at a given level
	void printGivenLevel(Node root, int level) {
		if (root == null)
			return;
		if (level == 1)
			System.out.print(root.data + " ");
		else if (level > 1) {
			printGivenLevel(root.left, level-1);
			printGivenLevel(root.right, level-1);
		}
	}

	// Compute the height of a tree - the number of nodes along the longest path from the root node down to the farthest leaf node
	int height(Node root) {
		if (root == null)
			return 0;
		else {
			// Compute the height of each subtree
			int lheight = height(root.left);
			int rheight = height(root.right);

			// Use the larger one
			if(lheight > rheight)
				return lheight + 1;
			else
				return rheight + 1;
		}
	}

	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root 		= new Node(1);
		tree.root.left		= new Node(2);
		tree.root.right		= new Node(3);
		tree.root.left.left	= new Node(4);
		tree.root.left.right	= new Node(5);

		tree.printLevelOrder();
		System.out.println();
	}
}
