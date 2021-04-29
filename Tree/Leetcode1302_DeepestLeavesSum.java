// Given the root of a binary tree, return the sum of values of its deepest leaves

import java.util.Queue;
import java.util.LinkedList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Leetcode1302_DeepestLeavesSum {
    public int deepestLeavesSum(TreeNode root) {
        int res = 0;
        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        while (!q.isEmpty()) {
            res = 0;
            for (int i = q.size() - 1; i >= 0; i--) {
                TreeNode curr = q.poll();
                res += curr.val;
                if (curr.left != null) {
                    q.add(curr.left);
                }
                if (curr.right != null) {
                    q.add(curr.right);
                }
            }
        }

        return res;
    }
}
