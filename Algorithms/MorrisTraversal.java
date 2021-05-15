// Using Morris Traversal, we can traverse the tree without using stack and recursion.

class TreeNodeMT {
    int val;
    TreeNodeMT left, right;

    TreeNodeMT() {
        val = 0;
        left = right = null;
    }

    TreeNodeMT(int val) {
        this.val = val;
        left = right = null;
    }
}

public class MorrisTraversal {
    TreeNodeMT root;

    void morrisTraversal(TreeNodeMT root) {
        TreeNodeMT current, pre;

        if (root == null) {
            return;
        }

        current = root;

        while (current != null) {
            if (current.left == null) {
                System.out.println(current.val + " ");
                current = current.right;
            } else {
                // find the inorder predecessor of current
                pre = current.left;
                while (pre.right != null && pre.right != current) {
                    pre = pre.right;
                }

                // make current as the right child of its predecessor
                if (pre.right == null) {
                    pre.right = current;
                    current = current.left;
                } else {
                    // revert changes to the tree
                    pre.right = null;
                    System.out.println(current.val + " ");
                    current = current.right;
                }
            }
        }
    }

    public static void main(String[] args) {
        /* Constructed binary tree is
               1
             /   \
            2      3
          /   \
         4     5
        */
        MorrisTraversal tree = new MorrisTraversal();
        tree.root = new TreeNodeMT(1);
        tree.root.left = new TreeNodeMT(2);
        tree.root.right = new TreeNodeMT(3);
        tree.root.left.left = new TreeNodeMT(4);
        tree.root.left.right = new TreeNodeMT(5);
 
        tree.morrisTraversal(tree.root);
    }
}
