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
    int dfsHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=dfsHeight(root->left);
        int right=dfsHeight(root->right);

        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
       if(root==NULL){
        return 0;
       }

        int maxi=0;

        int left=dfsHeight(root->left);
        int right=dfsHeight(root->right);

        int currentDiameter=left+right;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currentDiameter,max(leftDiameter,rightDiameter));


    }
};