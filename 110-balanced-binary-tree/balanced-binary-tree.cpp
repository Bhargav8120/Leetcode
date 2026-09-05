/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    bool isBalanced(TreeNode *root){
    	//your code goes here
        return dfsHeight(root)!=-1;
    }

    int dfsHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=dfsHeight(root->left);

        if(left==-1) return -1;

        int right=dfsHeight(root->right);

        if(right==-1) return -1;

        if(abs(left-right)>1) return -1;

        return 1 + max(left,right);
    }
};