// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
// Nary-Tree input serialization is represented in their level order traversal. 
// Each group of children is separated by the null value (See examples)

import java.util.*;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

public class Leetcode_589_nary_preorder {
    void naryPreorder(Node root, List<Integer> ans) {
        if(root == null)
            return;
        
        ans.add(root.val);
        
        for(Node child : root.children) {
            naryPreorder(child, ans);
        }       
        
    }
    
    public List<Integer> preorder(Node root) {
        List<Integer> ans = new ArrayList<Integer>();
        
        naryPreorder(root, ans);
        
        return ans;
    }
}
