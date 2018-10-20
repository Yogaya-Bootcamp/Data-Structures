import java.util.LinkedList;
import java.util.Queue;

class BinaryTreeInsertion {
	
	static class Node {
		int data;
		Node left, right;

		Node(int data) {
			this.data = data;
			left = null;
			right = null;
		}
	}

	static Node root;
	
	// Reverse Inorder traversal
	static void inorder(Node temp) {
		if (temp == null)
			return;
		inorder(temp.left);
		System.out.print(temp.data + " ");
		inorder(temp.right);
	}

	static void insert(Node temp, int key) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(temp);
		
		while(!q.isEmpty()) {
			temp = q.peek();
			q.remove();
		
			if(temp.right == null) {
				temp.right = new Node(key);
				break;
			} else
				q.add(temp.right);

		
			if(temp.left == null) {
				temp.left = new Node(key);
				break;
			} else
				q.add(temp.left);
		}
	}

	public static void main(String[] args) {
		root = new Node(10);
		root.left = new Node(11);
		root.right = new Node(9);
		root.left.left = new Node(7);
		root.right.left = new Node(15);
		
		System.out.print("Inorder traversal before insertion: ");
		inorder(root);

		int key = 12;
		insert(root, key);

		System.out.print("\nInorder traversal after insertion: ");
		inorder(root);
		System.out.println();
	}
}
