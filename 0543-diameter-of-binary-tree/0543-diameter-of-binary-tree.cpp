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
    int maxi=0;
    int findH(TreeNode* root){
        if(root==NULL) return 0;
        return max(findH(root->left),findH(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL) return 0;
        int lh=findH(root->left);
        int rh=findH(root->right);
       
        maxi=max(maxi,lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};