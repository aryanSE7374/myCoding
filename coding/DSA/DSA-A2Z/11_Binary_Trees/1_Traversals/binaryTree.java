class Node {
    int data;
    Node left, right;

    // Constructor
    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

public class binaryTree {
    public static void main(String[] args) {
        /*
              Creating this tree:
                    1
                   / \
                  2   3
                 / \
                4   5
        */

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        System.out.println("Root node data: " + root.data);
        System.out.println("Left child of root: " + root.left.data);
        System.out.println("Right child of root: " + root.right.data);
        System.out.println("Left child of root's left child: " + root.left.left.data);
    }
}