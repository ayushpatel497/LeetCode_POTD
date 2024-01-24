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
    int ans=0;
    void preorder(TreeNode* node, int ct){
        if(node==NULL)
            return;
        ct^=(1<<node->val);
        if(!node->left && !node->right)
            ans+=(ct&(ct-1))==0;
        preorder(node->left,ct);
        preorder(node->right,ct);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root,0);
        return ans;
    }
};