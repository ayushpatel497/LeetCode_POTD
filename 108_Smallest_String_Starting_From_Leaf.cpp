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
public:
    string ans = "~";
    void helper(TreeNode* root, string str){
        if(!root)
            return;
        if(!root->left && !root->right)
            ans = min(ans, char(root->val + 'a') + str);
        helper(root->left, char(root->val + 'a') + str);
        helper(root->right, char(root->val + 'a') + str);
    }

    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};