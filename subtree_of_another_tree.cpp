/*
 * Subtree of another Tree
 * Problem: https://leetcode.com/problems/subtree-of-another-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:

    inline vector<TreeNode*> get_candidates(TreeNode *root, int value) {
        stack<TreeNode*> st;
        st.push(root);
        vector<TreeNode*> roots;
        while (!st.empty()) {
            TreeNode *u = st.top(); st.pop();
            if (u->val == value) {
                roots.push_back(u);
            }
            if (u->left != nullptr) {
                st.push(u->left);
            }
            if (u->right != nullptr) {
                st.push(u->right);
            }
        }
        return roots;
    }

    inline bool match(TreeNode *a, TreeNode *b) {
        stack<TreeNode*> st_a, st_b;
        st_a.push(a); st_b.push(b);
        while (!st_a.empty() && !st_b.empty()) {
            TreeNode *u = st_a.top(); st_a.pop();
            TreeNode *v = st_b.top(); st_b.pop();
            if (u->val != v->val || ((u->left == nullptr) ^ (v->left == nullptr))
               || ((u->right == nullptr) ^ (v->right == nullptr))) {
                return false;
            }
            if (u->left != nullptr) {
                st_a.push(u->left);
                st_b.push(v->left);
            }
            if (u->right != nullptr) {
                st_a.push(u->right);
                st_b.push(v->right);
            }
        }
        return st_a.empty() && st_b.empty();
    }

public:

    bool isSubtree(TreeNode *s, TreeNode *t) {
        if ((s == nullptr) ^ (t == nullptr)) {
            return false;
        }
        if (s == nullptr && t == nullptr) {
            return true;
        }
        vector<TreeNode*> roots = get_candidates(s, t->val);
        for (TreeNode *root : roots) {
            if (match(root, t)) {
                return true;
            }
        }
        return false;
    }

};
