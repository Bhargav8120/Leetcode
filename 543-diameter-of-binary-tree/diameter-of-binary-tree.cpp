/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
        int diameter=0;

        height(root,diameter);

        return diameter;
    }

    int height(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }

        int left=height(root->left,diameter);

        int right=height(root->right,diameter);

        diameter=max(diameter,left+right);

        return 1 + max(left,right);
    }
};