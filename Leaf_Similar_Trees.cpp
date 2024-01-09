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
    void sequenceFill(TreeNode* r,vector<int>&v){
        if(!r) return;
        if(!r->left && !r->right) {
            v.push_back(r->val);
        }
        sequenceFill(r->left,v);
        sequenceFill(r->right,v);
    }    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seqr1,seqr2;
        sequenceFill(root1,seqr1);
        sequenceFill(root2,seqr2);
        return seqr1==seqr2;
    }
};