// Given a binary tree, we install cameras on the nodes of the tree. 
// Each camera at a node can monitor its parent, itself, and its immediate children.
// Calculate the minimum number of cameras needed to monitor all nodes of the tree.
// O(N) time complexity -> each node visited once
// O(logN) space complexity -> recursive stack O(recursive depth) which is worst case O(N)

public class Leetcode_968_BinaryTreeCameras {
    private int notMonitored = 0;
    private int covered = 1;
    private int monitoredWithCam = 2;
    private int cameras = 0;

    public int minCameraCover(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int top = dfs(root);
        cameras += (top == notMonitored) ? 1 : 0;

        return cameras;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return covered;
        }

        int left = dfs(root.left);
        int right = dfs(root.right);

        if (left == covered && right == covered) {
            return notMonitored;
        } else if (left == notMonitored || right == notMonitored) {
            cameras++;
            return monitoredWithCam;
        } else {
            return covered;
        }
    }
}
