/* 
    problem : 94. Binary Tree Inorder Traversal
    url : https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    //전역 변수 활용 가능
    //vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        printTree(root,&result);
        return result;
    }
    // Left -> Root -> Right
    void printTree(TreeNode* root, vector<int>* pointer){
        if(root == NULL) return;
        printTree(root->left, pointer);
        (*pointer).push_back(root->val);
        printTree(root->right,pointer);
    }
};


