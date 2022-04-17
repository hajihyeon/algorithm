/* 
    problem : Convert Sorted Array to Binary Search Tree
    url : https://leetcode.com/problems/find-center-of-star-graph/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = new TreeNode();
        int n = nums.size()-1;
        getMid(nums,0,n,root);
        return root;
    }
    void getMid(vector<int>& nums, int start, int end, TreeNode* root){
        //end까지 cover
        int index = (end+start)/2;
        int num = nums[index];
        root->val = num;
        
        if(start<=index-1){
            root->left =  new TreeNode();
            getMid(nums,start,index-1, root->left);
        }
        if(end>=index+1){
            root->right = new TreeNode();
            getMid(nums, index+1,end, root->right);
        }
        
    }
};