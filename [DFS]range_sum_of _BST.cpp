/* 
    problem : Range Sum of BST
    url : https://leetcode.com/problems/range-sum-of-bst/
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
public:
    int sum = 0;
    int l=0;
    int h=0;
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        l=low;
        h=high;
        findsum(root);
        return sum;
    }
    void findsum(TreeNode* root){
        if(!root){
            return;
        }
        if(root->val>=l&& root->val<=h){
            sum+=root->val;
        }
        findsum(root->left);
        findsum(root->right);
    }
};



