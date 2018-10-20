import java.util.*;
import java.lang.*;
import java.io.*;

class BinaryTree {
	public static void main(String[] args) {
		TreeAsArray tree = new TreeAsArray();
		tree.setRootNode("A");
		//tree.setLeftNode(0, "B");
		tree.setRightNode(0, "C");
		tree.setLeftNode(1, "D");
		tree.setRightNode(1, "E");
		tree.setLeftNode(2, "F");

		tree.printTreeArr();
	}
}

class TreeAsArray {
	int root = 0;
	String[] arr = new String[10];

	public void setRootNode(String key) {
		arr[0] = key;
	}

	public void setLeftNode(int nodeIndex, String key) {
		if(arr[nodeIndex] == null) {
			System.out.format("Can't insert here:%d buddy\n", nodeIndex);
			return;
			
		}
		int leftNodeIndex  = (nodeIndex * 2) + 1;
		arr[leftNodeIndex] = key;
	}

	public void setRightNode(int nodeIndex, String key) {
		if(arr[nodeIndex] == null) {	
			System.out.format("Can't insert here:%d buddy\n", nodeIndex);
			return;
		}
		int rightNodeIndex = (nodeIndex * 2) + 2;
		arr[rightNodeIndex] = key;
	}

	public void printTreeArr() {
		for(int i = 0; i < 10; i++) {
			if(arr[i] != null)
				System.out.print(arr[i]);
			else
				System.out.print("-");
		}
		System.out.println();
	}
}
