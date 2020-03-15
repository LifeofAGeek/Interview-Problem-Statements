/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    int maxi=-1;  
    map<int,int>m; // map of how many times a particular sum occurs
    int dfs(TreeNode* root){
        if(root==NULL) // 
            return 0;
        int total=dfs(root->left)+dfs(root->right)+root->val;
        maxi=max(maxi,++m[total]); // it stores how many times the maximum frequency occured
        return total; // the total of that tree
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root); 
        vector<int>ans;  // final vector array
        for(auto &i : m){  // map which store the frequency
            if(i.second==maxi){  
                ans.push_back(i.first);  // push the ans in the final array
            }
        }
        return ans;  // returning the vector
    }
};
