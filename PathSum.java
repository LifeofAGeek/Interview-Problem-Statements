/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        
        // if root is null or its data > sum, return false
        if(root == null) {
            return false;
        }
        
        if(root.val == sum) {
            if(root.left == null && root.right == null) {
                return true;   
            }
        }
        
        // check if there exists a path in left or right subtree with updated sum
        boolean leftSum = hasPathSum(root.left, sum - root.val);
        boolean rightSum = hasPathSum(root.right, sum - root.val);
    
        if(leftSum == true || rightSum == true) {
            return true;
        }
        return false;
    }
}
