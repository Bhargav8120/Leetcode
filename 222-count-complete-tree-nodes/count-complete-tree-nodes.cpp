/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int countNodes(TreeNode* root) { 
        //your code goes here
        return dfs(root);
    }

    int dfs(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int lh,rh;

        lh=leftHeight(root);
        rh=rightHeight(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        int left=dfs(root->left);
        int right=dfs(root->right);

        return 1 + (left+right);

    }

    int rightHeight(TreeNode* root){

        int rh=0;

        if(root==NULL){
            return 0;
        }

        while(root!=NULL){
            root=root->right;
            rh++;
        }

        return rh;
    
    }
    int leftHeight(TreeNode* root){

        int lh=0;

        if(root==NULL){
            return 0;
        }

        while(root!=NULL){
            root=root->left;
            lh++;
        }

        return lh;
    }
};